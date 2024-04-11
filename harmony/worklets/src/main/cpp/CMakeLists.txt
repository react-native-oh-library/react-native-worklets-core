cmake_minimum_required(VERSION 3.13)
project(worklets)
#set(CMAKE_VERBOSE_MAKEFILE on)
set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

if(DEFINED PACKAGE_FIND_FILE)
    include(${PACKAGE_FIND_FILE})
endif()

include_directories(${NATIVERENDER_ROOT_PATH}
                    ${NATIVERENDER_ROOT_PATH}/include)

file(GLOB rnoh_worklets_SRC CONFIGURE_DEPENDS *.cpp)
file(GLOB WKT_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/WKT/*.cpp)
add_library(rnoh_worklets SHARED ${rnoh_worklets_SRC} ${WKT_SOURCES})

target_include_directories(rnoh_worklets PRIVATE
    ${NATIVERENDER_ROOT_PATH}
    ${NATIVERENDER_ROOT_PATH}/include
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/WKT
)

target_link_libraries(rnoh_worklets PUBLIC rnoh)
