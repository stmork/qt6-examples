cmake_minimum_required(VERSION 3.16)

project(Qt6-Examples
	VERSION 1.0
	DESCRIPTION "Some small Qt6 examples.")

add_compile_options(-Wextra -Wpedantic -Werror)
add_compile_options(-fstack-protector-strong)
add_compile_options(-Wshadow)

add_subdirectory(settings)

add_custom_target(cppcheck
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMAND cppcheck
    --inline-suppr
    --enable=style,warning,performance,portability
    --language=c++ --std=c++17
    --library=qt
    --xml-version=2 --force -q -j 2
    */*.cpp */*.h
    2>cppcheck.xml
)

set_property(
    TARGET cppcheck
    APPEND
    PROPERTY ADDITIONAL_CLEAN_FILES ${CMAKE_SOURCE_DIR}/cppcheck.xml
)
