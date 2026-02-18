cmake_minimum_required(VERSION 3.10)
project(Ahrify)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(external/raylib)
add_subdirectory(external/json)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} raylib)
target_include_directories(
    ${PROJECT_NAME} PUBLIC external/raylib/src
    ${PROJECT_NAME} PUBLIC external/json/single_include
    ${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
)

if(WIN32)
    # Statically link the standard libraries
    target_link_options(${PROJECT_NAME} PRIVATE "-static-libgcc" "-static-libstdc++" "-static")
endif()
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/src/themes" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")