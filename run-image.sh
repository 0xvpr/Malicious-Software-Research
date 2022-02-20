#!/bin/sh

# Creator:    VPR
# Created:    February 20th, 2022
# Updated:    February 20th, 2022

# Description:
#     Mounts local current working directory to /root in the container

IMAGE="mw-dev"
MOUNT_DIR="${PWD}"

docker run -itv "${MOUNT_DIR}:/root:z" "${IMAGE}"
