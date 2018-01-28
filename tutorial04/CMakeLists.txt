set(LIB_LIST
    glfw3
    GLEW 
    pthread
    GL
    X11
    m
    dl)

add_executable(tutorial04_triangle_vao tutorial04_triangle_vao.cpp)
target_link_libraries(tutorial04_triangle_vao ${LIB_LIST})



