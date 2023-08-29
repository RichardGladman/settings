add_library(${CMAKE_PROJECT_NAME}_lib Setting.cpp Settings.cpp)

target_include_directories(${CMAKE_PROJECT_NAME}_lib
                                PUBLIC
                                $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
                                $<INSTALL_INTERFACE:include/settings>)

