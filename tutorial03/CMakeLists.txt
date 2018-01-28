set(LIB_LIST
    glfw3
    GLEW 
    pthread
    GL
    X11
    m
    dl)

add_executable(tutorial03_triangle_vbo tutorial03_triangle_vbo.cpp)
target_link_libraries(tutorial03_triangle_vbo ${LIB_LIST})



