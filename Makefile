# Root directory of the WASI SDK
WASI_SDK_PATH ?=/opt/wasi-sdk
# Custom CFLAGS
WASI_CFLAGS ?=
# Install target
DESTDIR ?=/opt

CC=$(WASI_SDK_PATH)/bin/clang
WASI_BASE_CFLAGS= \
  --sysroot=$(WASI_SDK_PATH)/share/wasi-sysroot \
  -g \
  --target=wasm32-unknown-wasi \
  -D_WASI_EMULATED_SIGNAL \
  -I$(WASI_SDK_PATH)/share/wasi-sysroot/include \
  -isystem ./include

AR=$(WASI_SDK_PATH)/bin/llvm-ar
INSTALL=install

HEADERS_INCLUDE=$(wildcard include/*.h)
HEADERS_INCLUDE_SYS=$(wildcard include/sys/*.h)
HEADERS=$(HEADERS_INCLUDE) $(HEADERS_INCLUDE_SYS)
OBJS=$(patsubst %.c, %.o, $(wildcard src/*.c))
LIBWASIX_A=libwasix.a

.PHONY: all
all: $(LIBWASIX_A)

.PHONY: all_abort
all_abort:
	$(MAKE) clean
	$(MAKE) all WASI_CFLAGS="-D_WASIX_ABORT_ON_ERROR"

$(LIBWASIX_A): $(OBJS)
	$(AR) rcs $@ $^

$(OBJS): $(HEADERS)

.c.o:
	$(CC) $(WASI_BASE_CFLAGS) $(WASI_CFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -rf $(LIBWASIX_A) $(OBJS)

.PHONY: install
install: $(LIBWASIX_A) $(HEADERS)
	$(INSTALL) -D -p -t $(DESTDIR)/include $(HEADERS_INCLUDE)
	$(INSTALL) -D -p -t $(DESTDIR)/include/sys $(HEADERS_INCLUDE_SYS)
	$(INSTALL) -D -p -t $(DESTDIR)/lib $(LIBWASIX_A)
