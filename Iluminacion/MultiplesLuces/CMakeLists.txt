cmake_minimum_required(VERSION 3.9)
project(MultiplesLuces)

set(CMAKE_CXX_STANDARD 11)

add_executable(MultiplesLuces main.cpp glad.c Shader.cpp camera.cpp stb_image.cpp)

include_directories(glad/include/)

target_link_libraries(MultiplesLuces glfw X11 Xi Xrandr Xxf86vm Xinerama Xcursor dl pthread)