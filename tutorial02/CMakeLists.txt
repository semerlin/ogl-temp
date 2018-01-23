set(LIB_LIST
    glfw3
    pthread
    GL
    X11
    m
    dl)

add_executable(tutorial2 tutorial2.cpp)
target_link_libraries(tutorial2 ${LIB_LIST})


