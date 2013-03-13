cmake_minimum_required(VERSION 2.8)

project(3DMazeThingy)

find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

include_directories(SYSTEM ${SDL_INCLUDE_DIR})
include_directories(SYSTEM ${OPENGL_INCLUDE_DIR})

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANGXX OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_definitions("-std=c++11 -pedantic -Wall -Wextra")
endif ()

add_executable(maze
.gitignore
Camera.cpp
Camera.hpp
Clock.hpp
Collision.cpp
Collision.hpp
Config.cpp
Config.hpp
Plane.cpp
Plane.hpp
Texture.cpp
Texture.hpp
Wall.cpp
Wall.hpp
main.cpp
res/floor.png
res/wall.png
)

target_link_libraries(maze ${SDL_LIBRARY} ${OPENGL_LIBRARY} ${SDLIMAGE_LIBRARY} ${GLEW_LIBRARY})
