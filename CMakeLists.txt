cmake_minimum_required(VERSION 3.27)

project(settings VERSION 0.0.2)

add_subdirectory(src)

install(FILES include/setting.h include/settings.h DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${CMAKE_PROJECT_NAME})

install(TARGETS ${CMAKE_PROJECT_NAME}_lib EXPORT export_${CMAKE_PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/${CMAKE_PROJECT_NAME})

install(EXPORT export_${CMAKE_PROJECT_NAME}
        FILE ${CMAKE_PROJECT_NAME}-config.cmake
        NAMESPACE ${CMAKE_PROJECT_NAME}::
        DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/${CMAKE_PROJECT_NAME})
