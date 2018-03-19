cmake_minimum_required(VERSION 3.9)
project(Coordenadas)

set(CMAKE_CXX_STANDARD 11)

add_executable(Coordenadas main.cpp glad.c Shader.cpp stb_image.cpp KeyBoard.cpp KeyBoard.h)

include_directories(glad/include)

target_link_libraries(Coordenadas glfw3 X11 Xi Xrandr Xxf86vm Xinerama Xcursor dl pthread)