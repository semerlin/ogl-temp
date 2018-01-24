set(LIB_LIST
    glfw3
    GLEW
    pthread
    GL
    X11
    m
    dl)

add_executable(tutorial03 tutorial03.cpp)
target_link_libraries(tutorial03 ${LIB_LIST})


