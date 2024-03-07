cmake_minimum_required(VERSION 3.16)

add_compile_options(-g -rdynamic -Werror)

set (CMAKE_CXX_STANDARD 17)

file(GLOB ROOT_SOURCE src/*.cpp)
file(GLOB ROOT_HEADER src/*.hpp)
set(GLAD_SOURCE libs/glad/src/glad.c)
set(GLAD_INCLUDE libs/glad/include/glad/glad.h libs/glad/include/KHR/khrplatform.h)

project(OpenGLAPI VERSION 1.0.1 DESCRIPTION "API to make opengl programming easier")

set(SOURCES ${ROOT_SOURCE} ${ROOT_HEADER} ${GLAD_SOURCE} ${GLAD_INCLUDE})

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE "libs" "libs/glad/include")

target_link_libraries(${PROJECT_NAME} glfw OpenGL::GL)

install(TARGETS ${PROJECT_NAME})
