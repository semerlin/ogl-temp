set(LIB_LIST
    glfw3
    GLEW 
    pthread
    GL
    X11
    m
    dl)

add_executable(tutorial02_dot tutorial02_dot.cpp)
target_link_libraries(tutorial02_dot ${LIB_LIST})



