cmake_minimum_required(VERSION 3.1)

project(SFMLTest)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

set(SOURCES main.cpp)

## In most cases better set in the CMake cache
set(SFML_DIR ${PROJECT_SOURCE_DIR}/SFML-2.5.0)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio sfml-system)