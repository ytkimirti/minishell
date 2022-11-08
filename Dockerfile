FROM ubuntu:18.04

RUN apt-get update

RUN apt-get install -y build-essential \
strace ltrace curl wget gcc	\
net-tools vim gdb python \
make git wget fish sudo

# python3 python3-pip python3-dev libssl-dev libffi-dev wget git make
# gcc-multilib gdb-multiarch 

RUN useradd -d /home/hamsi/ -m -p hamsi -s /bin/bash hamsi

WORKDIR /home/hamsi

COPY . .

# RUN chown -R root:root /home/hamsi

RUN mkdir -p /home/hamsi/.ssh

RUN chown -R hamsi:hamsi /home/user/.ssh

USER hamsi

CMD /bin/bash
