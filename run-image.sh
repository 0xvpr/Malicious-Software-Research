#!/bin/sh

# Creator:    VPR
# Created:    February 9th, 2022
# Updated:    February 9th, 2022

__docker_img="mw-dev"

# Mounts local current working directory to /home/utopia in the container
docker run -itv ${PWD}:/root:z "${__docker_img}"
