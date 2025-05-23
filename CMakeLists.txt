cmake_minimum_required(VERSION 3.15)
project(main LANGUAGES C ASM)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I${CMAKE_SOURCE_DIR}/include -nostdlib -nostartfiles -W -g3 -no-pie")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -nostdlib -nostartfiles -no-pie")

file(GLOB_RECURSE SRC_C CONFIGURE_DEPENDS "src/*.c")
file(GLOB_RECURSE SRC_S CONFIGURE_DEPENDS "src/*.s")

add_executable(main ${SRC_C} ${SRC_S})
