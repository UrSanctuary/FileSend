set(CMAKE_INCLUDE_CURRENT_DIR ON)

set (SOURCES
    ClientList.cpp
    ClientList.h
    FakeConnection.cpp
    FakeConnection.h
    FileList.cpp
    FileList.h
    FileStorage.cpp
    FileStorage.h
    main.cpp
    qml.qrc
)

qt_wrap_cpp(SOURCES
    ClientList.h
    FileList.h
    FileStorage.h
)

add_executable(server ${SOURCES})

target_link_libraries(server PRIVATE Qt5::Core Qt5::Quick)

