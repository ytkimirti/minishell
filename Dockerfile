FROM ubuntu:18.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt update && apt install -y \
valgrind gcc make \
libncurses5-dev vim wget \
autoconf automake git
# && rm -rf /var/lib/apt/lists/*

RUN git clone https://sourceware.org/git/valgrind.git \
&& cd valgrind \
&& ./autogen.sh \
&& ./configure \
&& make \
&& make install

WORKDIR /minishell

COPY . .

RUN make -j8

# RUN make

CMD [ "bash" ]
