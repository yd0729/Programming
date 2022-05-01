# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(recipe-04 LANGUAGES CXX)

# 引入一个变量 USE_LIBRARY ，这是一个 bool ．
set(USE_LIBRARY OFF)

# 打印
message(STATUS "Compile sources into a library? ${USE_LIBRARY}")

# BUILD_SHARED_LIBS is a global flag offered by CMake
# to toggle the behavior of add_library
set(BUILD_SHARED_LIBS OFF)

# 引入一个变量 _sources ，这是一个列表
list(APPEND _sources Message.hpp Message.cpp)

if(USE_LIBRARY)
  # add_library will create a static library
  # since BUILD_SHARED_LIBS is OFF
  add_library(message ${_sources})

  add_executable(hello-world hello-world.cpp)

  target_link_libraries(hello-world message)
else()  # () 是历史原因，也可以写成 else(USE_LIBRARY)
  add_executable(hello-world hello-world.cpp ${_sources})
endif()
