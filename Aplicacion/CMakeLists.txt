cmake_minimum_required(VERSION 3.9)
project(Aplicacion)

set(CMAKE_CXX_STANDARD 11)

add_executable(Aplicacion main.cpp glad.c Utils/Shader.cpp stb_image.cpp Core/Aplicacion.cpp Core/Aplicacion.h Core/Window.cpp Core/Window.h Utils/texture.cpp Utils/texture.h Utils/resource_manager.cpp Utils/resource_manager.h Utils/sprite_renderer.cpp Utils/sprite_renderer.h Game/game_object.cpp Game/game_object.h Game/game_level.cpp Game/game_level.h Game/Game.cpp Game/Game.h)

include_directories(glad/include/)

target_link_libraries(Aplicacion glfw X11 Xi Xrandr Xxf86vm Xinerama Xcursor dl pthread)