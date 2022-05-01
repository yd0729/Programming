# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(recipe-05 LANGUAGES CXX)

# expose options to the user
#      变量名称     帮助字符串                         默认值
option(USE_LIBRARY "Compile sources into a library" OFF)

message(STATUS "Compile sources into a library? ${USE_LIBRARY}")

# 这个模块需要先 include
include(CMakeDependentOption)

# second option depends on the value of the first
# 这个选项取决于第 1 个选项，只有 USE_LIBRARY = ON ，这个选项才有意义．
cmake_dependent_option(
  MAKE_STATIC_LIBRARY "Compile sources into a static library" OFF
  "USE_LIBRARY" ON
  )

# third option depends on the value of the first
cmake_dependent_option(
  MAKE_SHARED_LIBRARY "Compile sources into a shared library" ON
  "USE_LIBRARY" ON
  )

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# list sources
list(APPEND _sources Message.hpp Message.cpp)

if(USE_LIBRARY)
  message(STATUS "Compile sources into a STATIC library? ${MAKE_STATIC_LIBRARY}")
  message(STATUS "Compile sources into a SHARED library? ${MAKE_SHARED_LIBRARY}")

  if(MAKE_SHARED_LIBRARY)
    add_library(message SHARED ${_sources})

    add_executable(hello-world hello-world.cpp)

    target_link_libraries(hello-world message)
  endif()

  if(MAKE_STATIC_LIBRARY)
    add_library(message STATIC ${_sources})

    add_executable(hello-world hello-world.cpp)

    target_link_libraries(hello-world message)
  endif()
else()
  add_executable(hello-world hello-world.cpp ${_sources})
endif()
