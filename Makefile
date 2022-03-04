# Root directory of the WASI SDK
WASI_SDK_PATH ?= /opt/wasi-sdk

# Add WASI SDK tools to PATH
export PATH = $(WASI_SDK_PATH)/bin:$$PATH

all:
	cd src && clang --sysroot=$(WASI_SDK_PATH)/share/wasi-sysroot -g \
		--target=wasm32-unknown-wasi -D_WASI_EMULATED_SIGNAL \
		-I$(WASI_SDK_PATH)/share/wasi-sysroot/include \
		-isystem ../include -c *.c
	llvm-ar -r libwasix.a src/*.o

all_abort:
	cd src && clang --sysroot=$(WASI_SDK_PATH)/share/wasi-sysroot -g \
		--target=wasm32-unknown-wasi -D_WASI_EMULATED_SIGNAL \
		-d_WASIX_ABORT_ON_ERROR \
		-I$(WASI_SDK_PATH)/share/wasi-sysroot/include \
		-isystem ../include -c *.c
	llvm-ar -r libwasix.a src/*.o
