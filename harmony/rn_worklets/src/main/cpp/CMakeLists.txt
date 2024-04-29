cmake_minimum_required(VERSION 3.13)
set(CMAKE_VERBOSE_MAKEFILE on)
set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB rnoh_worklets_SRC CONFIGURE_DEPENDS *.cpp)
add_library(rnoh_worklets SHARED ${rnoh_worklets_SRC})
target_include_directories(rnoh_worklets PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(rnoh_worklets PUBLIC rnoh)
