cmake_minimum_required(VERSION 3.1)

project(SFMLTest)

set(CMAKE_CXX_COMPILER_ID "MinGW Makefiles")

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

set(SOURCES main.cpp)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(${PROJECT_NAME} ${SOURCES})
message(${CONAN_LIBS})
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})