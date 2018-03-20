cmake_minimum_required(VERSION 3.9)
project(IluBasica)

set(CMAKE_CXX_STANDARD 11)

add_executable(IluBasica main.cpp glad.c Shader.cpp camera.cpp)

include_directories(glad/include/)

target_link_libraries(IluBasica glfw X11 Xi Xrandr Xxf86vm Xinerama Xcursor dl pthread)