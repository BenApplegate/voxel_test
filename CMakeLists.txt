cmake_minimum_required(VERSION 3.22)
project(voxel_test)

set(CMAKE_CXX_STANDARD 17)


include_directories(voxel_test include)
add_executable(voxel_test main.cpp glad.c)
target_link_directories(voxel_test PUBLIC lib/glfw)
target_link_libraries(voxel_test opengl32)
target_link_libraries(voxel_test glfw3)
