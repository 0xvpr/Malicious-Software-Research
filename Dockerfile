# Creator:    VPR
# Created:    February 20th, 2022
# Updated:    May 29th, 2023

FROM ubuntu:22.04

# Set env to avoid user input interruption during installation
ENV TZ=America/New_York
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# Install normal goodies
RUN apt-get update && apt upgrade -y
RUN apt-get install -y --no-install-recommends zsh \
                                               zsh-autosuggestions \
                                               git \
                                               curl \
                                               wget \
                                               vim \
                                               tree \
                                               make \
                                               cmake \
                                               build-essential \
                                               mingw-w64 \
                                               gdb \
                                               python3-dev \
                                               nasm

# Change login shell to zsh
RUN chsh -s /bin/zsh $(whoami)

# Create Utopia user && dir
ENV HOME=/root
WORKDIR /opt/mw-dev
