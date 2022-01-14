
# WASIX

This library provides stubs for POSIX compatibility when compiling sources
using the [WASI SDK](https://github.com/WebAssembly/wasi-sdk). The WASI SDK
and the accomanying [wasi-libc](https://github.com/WebAssembly/wasi-libc) do
provide some POSIX functionality, but many functions that are not currently
supported or do not make sense in the context of WASM are missing. This can
make it difficult to compile sources to WASI that expect POSIX compatibility.

The library in this project aims to fill the gaps between POSIX and WASI.
In many cases, the implementation of functions will simply return an error
code, but it will allow many 3rd party sources to compile using WASI and
access any functionality that doesn't require the stubbed out functions.

Some functions (e.g., `getpid`, `getuid`, `getgid`) are implemented to return
a static value given at compile time or an environment variable specified
at runtime. This allows you to more closely emulate some POSIX functions
in your environment as needed.


## Build

The build requirements for WASIX are the same as for 
[WASI SDK](https://github.com/WebAssembly/wasi-sdk). The Makefile may
need to be changed to reflect the installation path of WASI SDK and
wasi-libc.

To build `libwasix.a`, simply run the Makefile:
```
make all
```

### Abort on Error

The default behavior for WASIX is to return an error code if a function
is not implemented. Depending on how the library is used, it may be preferable
to have the process abort when an unimplemented function is called. To
enable this behavior use the following build command:
```
make all_abort
```

## Use

To use `libwasix.a`, add the following options to your compilation step:
```
-isystem ${WASIX_DIR}/include
```

Then add the following options to your link step:
```
-L${WASIX_DIR} -lwasix
```


## Static Return Value Functions

Some functions in WASIX can be configured to return a static value rather
than an error. The following functions can be configured in the specified
ways.

| **Function** | **Environment Variable** | **Compile-Time Definition** | **Default** |
|--------------|--------------------------|-----------------------------|-------------|
| `getpid`     | `WASIX_PID`              | `-D_WASIX_PID=value`        | 66600       |
| `getppid`    | `WASIX_PPID`             | `-D_WASIX_PPID=value`       | 55500       |
| `getuid`     | `WASIX_UID`              | `-D_WASIX_UID=value`        | 1           |
| `geteuid`    | `WASIX_EUID`             | `-D_WASIX_EUID=value`       | 1           |
| `getgid`     | `WASIX_GID `             | `-D_WASIX_GID=value`        | 100         |
| `getegid`    | `WASIX_EGID`             | `-D_WASIX_EGID=value`       | 100         |

## Ignored Functions

Some functions in WASIX do nothing and return a successful return value. These
include `chmod`, `fchmod`, `chown`, `fchown`, and `umask` (returns `0755`).


## Resources

[WASM](https://webassembly.org)

[WASI SDK](https://github.com/WebAssembly/wasi-sdk) 
