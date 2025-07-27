FROM ubuntu:22.04

ENV PROJECT_ROOT="/home/workspace"

ENV LIB_ROOT="${PROJECT_ROOT}/data_structures_library"
ENV LIB_BUILD="${LIB_ROOT}/build"

SHELL ["/bin/bash", "-c"]
RUN mkdir /home/workspace
WORKDIR /home/workspace

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install clang -y
RUN apt-get install git -y
RUN apt-get install cmake -y
RUN apt-get install clang-tidy -y
RUN apt-get install libc++-14-dev -y
RUN apt-get install libc++abi-14-dev -y
RUN apt-get install llvm -y
