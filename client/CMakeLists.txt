set(CMAKE_INCLUDE_CURRENT_DIR ON)

set (SOURCES main.cpp)

add_executable(client main.cpp)

target_link_libraries(client PRIVATE Qt5::Core)

