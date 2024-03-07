cmake_minimum_required(VERSION 3.9)

set (CMAKE_CXX_STANDARD 17)

project(OpenGLAPI VERSION 1.0.1 DESCRIPTION "API to make opengl programming easier")

SET(SOURCES libs/glad/src/glad.c libs/glad/include/glad/glad.h libs/glad/include/KHR/khrplatform.h
	    src/OpenGLAPI.cpp src/InputManager.cpp
	    libs/glm/glm.hpp
	    libs/Shader.h)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE "libs" "libs/glad/include")

target_link_libraries(${PROJECT_NAME} OpenGL::GL glfw)
install(TARGETS ${PROJECT_NAME})
