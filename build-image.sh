#!/bin/sh

# Created by:   VPR
# Created:      February 20th, 2022

# Updated by:   VPR
# Updated:      February 3rd, 2024

# Description:
#     Builds docker image using root Dockerfile

set -e pipefail
set -e errexit
set -e nounset
set -e xtrace

IMAGE="mw-dev"
DOCKERFILE="Dockerfile"

docker build . --file "${DOCKERFILE}" --tag "${IMAGE}:${IMAGE}"
