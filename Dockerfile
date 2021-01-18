FROM fedora:latest

##
# Build arguments and runtime environment variables
##
ARG BUILD_TYPE=Release
ENV DISCORD_TOKEN=NO_TOKEN_SET

##
# Update system
##
RUN \
    yum update -y && \
    yum upgrade -y

##
# Install dependencies
##
RUN \
    yum install -y \
    gcc \
    g++ \
    git \
    cmake \
    make \
    openssl \
    openssl-devel

##
# Copy files over to workdir
##
WORKDIR /app
COPY . /app

##
# Pull all git submodules
##
RUN \
    git submodule update --init --recursive

##
# Build target
##
RUN \
    cmake -B build/ -DCMAKE_BUILD_TYPE=${BUILD_TYPE} && \
    cd build && \
    make

##
# Set image entrypoint
##
ENTRYPOINT ["./build/source/src"]