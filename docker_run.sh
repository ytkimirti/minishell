#!/bin/bash

if ! docker build -t ytkimirti/minishell .
then
	echo "Error while building" && exit 1
fi

echo "> Running the container"

if ! docker run --name minishell --cap-add=SYS_PTRACE -dit ytkimirti/minishell
then
	echo "Error while running" && exit 1
fi

echo "> Attaching to the container"
docker attach minishell
# docker start -a minishell

echo "> Stopping processes"
docker stop minishell
docker rm minishell

docker ps -a
