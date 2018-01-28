set(LIB_LIST
    glfw3
    GLEW 
    pthread
    GL
    X11
    m
    dl)

add_executable(tutorial01_window tutorial01_window.cpp)
target_link_libraries(tutorial01_window ${LIB_LIST})



