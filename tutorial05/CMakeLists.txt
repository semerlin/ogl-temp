set(LIB_LIST
    glfw3
    GLEW
    pthread
    GL
    X11
    m
    dl)

add_executable(tutorial05_shader tutorial05_shader.cpp)
target_link_libraries(tutorial05_shader ${LIB_LIST})


