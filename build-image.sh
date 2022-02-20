#!/bin/sh

# Creator:    VPR
# Created:    February 20th, 2022
# Updated:    February 20th, 2022

# Description:
#     Builds docker image using root Dockerfile

set -e pipefail
set -e errexit
set -e nounset
set -e xtrace

IMAGE="mw-dev"
DOCKERFILE="Dockerfile"

docker build . --file "${DOCKERFILE}" --tag "${IMAGE}:${IMAGE}"
