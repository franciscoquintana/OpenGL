cmake_minimum_required(VERSION 3.9)
project(Shaders)

set(CMAKE_CXX_STANDARD 11)

add_executable(Triangulo main.cpp glad.c Shader.cpp)

include_directories(glad/include)

target_link_libraries(Triangulo glfw3 X11 Xi Xrandr Xxf86vm Xinerama Xcursor dl pthread)