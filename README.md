Building on MAC
---

- `mkdir build`
- `cd build`
- `cmake -DCMAKE_INSTALL_PREFIX:PATH=$(pwd)/usr -DCMAKE_SYSTEM_PREFIX_PATH:PATH=$(pwd)/usr -DCMAKE_TOOLCHAIN_FILE=cmake/toolchains/clang.cmake ..`
- `make`
