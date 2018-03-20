cmake_minimum_required(VERSION 3.9)
project(Camara)

set(CMAKE_CXX_STANDARD 11)

add_executable(Camara main.cpp glad.c Shader.cpp stb_image.cpp KeyBoard.cpp camera.cpp)

include_directories(glad/include)

target_link_libraries(Camara glfw X11 Xi Xrandr Xxf86vm Xinerama Xcursor dl pthread)