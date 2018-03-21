cmake_minimum_required(VERSION 3.9)
project(MapeadoLuces)

set(CMAKE_CXX_STANDARD 11)

add_executable(MapeadoLuces main.cpp glad.c Shader.cpp camera.cpp stb_image.cpp)

include_directories(glad/include/)

target_link_libraries(MapeadoLuces glfw X11 Xi Xrandr Xxf86vm Xinerama Xcursor dl pthread)