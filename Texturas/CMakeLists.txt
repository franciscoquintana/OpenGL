cmake_minimum_required(VERSION 3.9)
project(Texturas)

set(CMAKE_CXX_STANDARD 11)

add_executable(Texturas main.cpp glad.c Shader.cpp stb_image.cpp)

include_directories(glad/include)

target_link_libraries(Texturas glfw3 X11 Xi Xrandr Xxf86vm Xinerama Xcursor dl pthread)