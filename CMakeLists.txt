cmake_minimum_required(VERSION 3.0)

project(settings)

add_executable(settings main.cpp)

install(TARGETS settings RUNTIME DESTINATION bin)
