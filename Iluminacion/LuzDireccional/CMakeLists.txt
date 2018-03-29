cmake_minimum_required(VERSION 3.9)
project(LuzDireccional)

set(CMAKE_CXX_STANDARD 11)

add_executable(LuzDireccional main.cpp glad.c Shader.cpp camera.cpp stb_image.cpp)

include_directories(glad/include/)

target_link_libraries(LuzDireccional glfw X11 Xi Xrandr Xxf86vm Xinerama Xcursor dl pthread)