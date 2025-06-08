cmake_minimum_required(VERSION 3.10)
project(CHIP8-EMULATOR VERSION 0.1.0 LANGUAGES C CXX)

# Incluye el directorio de headers
include_directories(include)

# Recoge todos los cpp de src/
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})

# Encontrar SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Enlazar con SDL2
target_link_libraries(${PROJECT_NAME}  ${SDL2_LIBRARIES})
