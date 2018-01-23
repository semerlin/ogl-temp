/************************************************************************
 * File Name: ogl.c
 * Author: HuangYang
 * Mail: elious.huang@gmail.com
 * Created Time: Sun 19 Nov 2017 09:13:37 PM CST
 ************************************************************************/
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

int main(int argc, char **argv)
{
    if (!glfwInit())
    {
        cout << "failed to initialize glfw" << endl;
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(640, 480, "test", NULL, NULL);
    if (NULL == window)
    {
        cout << "create window failed" << endl;
        return -1;
    }

    glfwMakeContextCurrent(window);

    cout << "opengl version = " << glGetString(GL_VERSION) << endl;

    //init glew
    if (GLEW_OK != glewInit())
    {
        cout << "failed to initialize glew" << endl;
        glfwTerminate();
        return -1;
    }

    //triangle coordinate
    GLfloat vertex_buffer[] = {-1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f};

    //create vao object
    GLuint vao_id;
    glGenVertexArrays(1, &vao_id);
    glBindVertexArray(vao_id);

    //create vbo object
    GLuint vbo_id;
    glGenBuffers(1, &vbo_id);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer), vertex_buffer, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDisableVertexAttribArray(0);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    do
    {
        glClear(GL_COLOR_BUFFER_BIT);

        //bind vao
        glBindVertexArray(vao_id);

        //draw model
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glBindVertexArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }while( glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
            glfwWindowShouldClose(window) == 0);

    glfwTerminate();

    return 0;
}

