#!/bin/sh

# Created by:   VPR
# Created:      February 20th, 2022

# Updated by:   VPR
# Updated:      February 3rd, 2024

# Description:
#     Mounts local current working directory to /root in the container

IMAGE="mw-dev"
MOUNT_DIR="${PWD}"

docker run -itv "${MOUNT_DIR}:/opt/-mw-dev:z" "${IMAGE}"
