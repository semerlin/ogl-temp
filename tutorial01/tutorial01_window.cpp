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

    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);

    do
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }while( glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
            glfwWindowShouldClose(window) == 0);

    glfwTerminate();

    return 0;
}

