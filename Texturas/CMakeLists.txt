cmake_minimum_required(VERSION 3.9)
project(Texturas)

set(CMAKE_CXX_STANDARD 11)

add_executable(Texturas main.cpp glad.c Shader.cpp stb_image.cpp KeyBoard.cpp KeyBoard.h)

include_directories(glad/include)

target_link_libraries(Texturas glfw X11 Xi Xrandr Xxf86vm Xinerama Xcursor dl pthread)