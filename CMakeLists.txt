cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(scope_tests)

set(APP_NAME scope_exit)

set(SHARED_INCLUDE_PATH ./include)
set(HEADERS include/scope_exit)
set(SOURCES src/main_scope_exit.cc)

add_executable(${APP_NAME} ${SOURCES} ${HEADERS})

set_target_properties(${APP_NAME} PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
target_include_directories(${APP_NAME} PUBLIC
    ${SHARED_INCLUDE_PATH}
)
target_compile_options(${APP_NAME} PUBLIC
    -pthread
    -pedantic
    -Wall
    -Wextra
    -Wshadow
    -Wpointer-arith
    -Wcast-qual
    -Wunused-result
    -g
)
