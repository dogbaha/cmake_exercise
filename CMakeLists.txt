cmake_minimum_required(VERSION 3.15)

project(cTest VERSION  0.1)
configure_file(cTestConfig.h.in cTestConfig.h)

option(USE_LOG "printf method by self" ON)

message( STATUS "CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME}" ) 
message( STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}" )

set(cmkae_cxx_standard 11)
set(cmake_cxx_standard_required true)
set(CMAKE_BUILD_TYPE "Debug")


if(USE_LOG)
    add_subdirectory(tools)
    list(APPEND extra_libs stringTool)
    list(APPEND extra_includes "${PROJECT_SOURCE_DIR}/tools")
endif()


add_executable(main cmakeTest.cpp)

target_link_libraries(main PUBLIC ${extra_libs})


target_include_directories( main PUBLIC 
                            "${PROJECT_BINARY_DIR}"
                            ${extra_includes}
                            
                            )