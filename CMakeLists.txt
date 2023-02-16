cmake_minimum_required(VERSION 3.25.2)
project(MySecurity)

IF (WIN32)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lws2_32")
ENDIF()

add_executable(${PROJECT_NAME} main.c)

add_subdirectory(libs)
add_subdirectory(handler)

target_include_directories(${PROJECT_NAME} PUBLIC handler)
target_include_directories(${PROJECT_NAME} PUBLIC libs)

target_link_directories(${PROJECT_NAME} PRIVATE handler/)
target_link_directories(${PROJECT_NAME} PRIVATE libs/)

target_link_libraries(${PROJECT_NAME} handler)
target_link_libraries(${PROJECT_NAME} socket)
