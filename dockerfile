FROM ubuntu:22.04

SHELL ["/bin/bash", "-c"]
RUN mkdir /home/workspace
WORKDIR /home/workspace

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install clang -y
RUN apt-get install git -y
RUN apt-get install cmake -y
