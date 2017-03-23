SET(CMAKE_SYSTEM_NAME Linux)

set(CMAKE_C_COMPILER gcc-5 -m32)

set(CMAKE_CXX_COMPILER g++-5 -m32)

set(CMAKE_LIBRARY_PATH /usr/lib32)

set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "i386")

set(CMAKE_CXX_STANDARD 11) # C++11

# The 32-bit environment sets int, long and pointer to 32 bits and generates code that runs on any i386 system.
# The 64-bit environment sets int to 32 bits and long and pointer to 64 bits and generates code for AMD's x86-64 architecture. 