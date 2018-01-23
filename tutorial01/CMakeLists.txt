set(LIB_LIST
    glfw3
    GLEW 
    pthread
    GL
    X11
    m
    dl)

add_executable(tutorial01 tutorial01.cpp)
target_link_libraries(tutorial01 ${LIB_LIST})



