cmake_minimum_required(VERSION 3.9)
project(MultiplesLuces)

set(CMAKE_CXX_STANDARD 11)

add_executable(MultiplesLuces main.cpp glad.c Shader.cpp camera.cpp stb_image.cpp imgui_impl_glfw_gl3.cpp imgui-1.53/imgui.cpp imgui-1.53/imgui_draw.cpp imgui-1.53/imgui_demo.cpp ui.cpp ui.h main.h)

include_directories(glad/include/ imgui-1.53/)

target_link_libraries(MultiplesLuces glfw X11 Xi Xrandr Xxf86vm Xinerama Xcursor dl pthread)