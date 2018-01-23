set(LIB_LIST
    glfw3
    GLEW 
    pthread
    GL
    X11
    m
    dl)

add_executable(tutorial02 tutorial02.cpp)
target_link_libraries(tutorial02 ${LIB_LIST})



