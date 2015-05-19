cmake_minimum_required(VERSION 3.2)

project(sandbox_cpp_icu)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})
set(ICU_INCLUDE_DIRS /usr/local/opt/icu4c/include)
set(ICU_LIBRARIES icuuc icui18n)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp)

include_directories(${ICU_INCLUDE_DIRS})
link_directories(/usr/local/opt/icu4c/lib)

add_executable(sandbox_cpp_icu ${SOURCE_FILES} main.h)
target_link_libraries(sandbox_cpp_icu ${ICU_LIBRARIES})