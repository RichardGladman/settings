add_library(${CMAKE_PROJECT_NAME}_lib setting.cpp settings.cpp)

target_include_directories(${CMAKE_PROJECT_NAME}_lib
                                PUBLIC
                                $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
                                $<INSTALL_INTERFACE:include/settings>)

