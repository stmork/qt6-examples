cmake_minimum_required(VERSION 3.16)

project(QSettingsExample LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(SettingsExample
  main.cpp
)

target_link_libraries(SettingsExample Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)

install(TARGETS SettingsExample
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
