set(LIB_LIST
    glfw3
    pthread
    GL
    X11
    m
    dl)

add_executable(tutorial1 tutorial1.cpp)
target_link_libraries(tutorial1 ${LIB_LIST})



