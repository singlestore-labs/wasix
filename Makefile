
all:
	cd src && clang --sysroot=/opt/wasi-sdk/share/wasi-sysroot -g \
		--target=wasm32-unknown-wasi -D_WASI_EMULATED_SIGNAL \
		-I/opt/wasi-sdk/share/wasi-sysroot/include \
		-isystem ../include -c *.c
	llvm-ar -r libwasix.a src/*.o

all_abort:
	cd src && clang --sysroot=/opt/wasi-sdk/share/wasi-sysroot -g \
		--target=wasm32-unknown-wasi -D_WASI_EMULATED_SIGNAL \
		-d_WASIX_ABORT_ON_ERROR \
		-I/opt/wasi-sdk/share/wasi-sysroot/include \
		-isystem ../include -c *.c
	llvm-ar -r libwasix.a src/*.o
