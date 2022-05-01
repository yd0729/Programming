# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(recipe-08 LANGUAGES CXX)

# 打印当前编译器标志。CMake将对所有C++目标使用这些标志。
message("C++ compiler flags: ${CMAKE_CXX_FLAGS}")

# 为目标准备标志列表，其中一些将无法在Windows上使用．
list(APPEND flags "-fPIC" "-Wall")
if(NOT WIN32)
  list(APPEND flags "-Wextra" "-Wpedantic")
endif()

# 添加了一个新的目标—— geometry 库，并列出它的源依赖关系
add_library(geometry
  STATIC
  geometry_circle.cpp
  geometry_circle.hpp
  geometry_polygon.cpp
  geometry_polygon.hpp
  geometry_rhombus.cpp
  geometry_rhombus.hpp
  geometry_square.cpp
  geometry_square.hpp
)

  # 为这个库目标设置编译选项
target_compile_options(geometry
  PRIVATE
  ${flags}
)

add_executable(compute-areas compute-areas.cpp)

target_compile_options(compute-areas
  PRIVATE
    "-fPIC"
  )

target_link_libraries(compute-areas geometry)
