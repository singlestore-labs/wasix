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
    libc6-dev-i386 \
    libtinfo5 \
    m4 \
    zip

RUN wget https://apt.llvm.org/llvm.sh && \
    chmod +x llvm.sh && \
    ./llvm.sh 13

RUN cd /opt && \
    wget https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-14/wasi-sdk-14.0-linux.tar.gz && \
    tar zxvf *.tar.gz && \
    rm *.tar.gz

RUN cd /usr/lib/clang/13 && \
    wget https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-14/libclang_rt.builtins-wasm32-wasi-14.0.tar.gz && \
    tar zxvf *.tar.gz && \
    rm *.tar.gz

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

RUN curl https://wasmtime.dev/install.sh -sSf | bash
RUN curl https://get.wasmer.io -sSfL | sh

RUN ln -s /usr/bin/clang-13 /usr/bin/clang
RUN ln -s /usr/bin/clang++-13 /usr/bin/clang++
RUN ln -s /usr/bin/wasm-ld-13 /usr/bin/wasm-ld
RUN mkdir -p /opt/wasi-sdk/share && ln -s /opt/wasi-sdk-14.0/share/wasi-sysroot /opt/wasi-sdk/share/wasi-sysroot

ENV PATH=${PATH}:/usr/lib/llvm-13/bin:/root/.wasmer/bin
ENV C_INCLUDE_PATH=/usr/include
ENV CPLUS_INCLUDE_PATH=/usr/include
ENV LIBRARY_PATH=/usr/lib/wasm32-wasi:/usr/lib/clang/13/lib/wasi

ENV WASMTIME_BACKTRACE_DETAILS=1

COPY lib/* /usr/local/lib/
COPY include/* /usr/local/include/

RUN mv /usr/include /usr/include-x86
RUN ln -s /opt/wasi-sdk/share/wasi-sysroot/include /usr/include
