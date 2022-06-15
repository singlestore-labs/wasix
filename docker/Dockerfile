FROM debian:bullseye

RUN apt-get update && apt-get install -y \
    wget \
    curl \
    lsb-release \
    software-properties-common \
    gnupg \
    vim \
    build-essential \
    libc6-dev \
    libtinfo5 \
    libxkbcommon-dev \
    m4 \
    zip \
    git \
    cmake \
    ninja-build

# WASI SDK
RUN cd /opt && \
    wget https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-16/wasi-sdk-16.0-linux.tar.gz && \
    tar zxvf *.tar.gz && \
    rm *.tar.gz && \
    ln -s /opt/wasi-sdk-16.0 /opt/wasi-sdk

# Autoconf
RUN cd /tmp && \
    wget http://ftp.gnu.org/gnu/autoconf/autoconf-2.71.tar.gz && \
    tar zxvf autoconf-*.tar.gz && \
    cd autoconf-* && \
    ./configure && make && make install

RUN cd /tmp && \
    wget http://ftp.gnu.org/gnu/automake/automake-1.16.tar.gz && \
    tar zxvf automake-*.tar.gz && \
    cd automake-* && \
    ./configure && make && make install

# WASM tools
RUN curl https://wasmtime.dev/install.sh -sSf | bash
RUN curl https://get.wasmer.io -sSfL | sh
RUN cd /opt && \
    git clone --recursive https://github.com/WebAssembly/wabt && \
    cd wabt && \
    git submodule update --init
RUN cd /opt/wabt && mkdir build && cd build && cmake .. && cmake --build .

ENV PATH=/opt/wasi-sdk/bin:/root/.wasmer/bin:/opt/wabt/build:${PATH}
ENV WASMTIME_BACKTRACE_DETAILS=1
ENV WASI_SDK_PATH=/opt/wasi-sdk
