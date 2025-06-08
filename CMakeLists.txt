cmake_minimum_required(VERSION 3.10)
project(HelloWorld VERSION 0.1.0 LANGUAGES C CXX)

# Incluye el directorio de headers
include_directories(include)

# Recoge todos los cpp de src/
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})
