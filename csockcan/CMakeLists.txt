cmake_minimum_required(VERSION 3.0)
project(CSockCAN)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES csockcan.c)

add_library(csockcan ${SOURCE_FILES})
set_target_properties(csockcan PROPERTIES LINKER_LANGUAGE "C")

install(TARGETS csockcan DESTINATION lib)
install(FILES csockcan.h DESTINATION include)
