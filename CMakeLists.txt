cmake_minimum_required(VERSION 3.16)

project(kometa VERSION 0.1 LANGUAGES C)

set(EXECUTABLE_OUTPUT_PATH ./${CMAKE_BUILD_TYPE})

set(INCLUDE_FILES
    
)

set(SRC_FILES
    main.c
)

list(TRANSFORM INCLUDE_FILES PREPEND ${CMAKE_CURRENT_SOURCE_DIR}/include/)
list(TRANSFORM SRC_FILES PREPEND ${CMAKE_CURRENT_SOURCE_DIR}/src/)

add_executable(kometa ${INCLUDE_FILES} ${SRC_FILES})
target_include_directories(kometa PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
