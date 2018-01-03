#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>

int main(int argc, char **argv)
{
    //gltSetWorkingDirectory(argv[0]);
    if (!glfwInit())
    {
        fprintf(stderr, "failed to initizlize GLFW\n");
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(1024, 768, "test", NULL, NULL);
    if (NULL == window)
    {
        fprintf(stderr, "failed to open GLFW window\n");
        return -1;
    }
    glfwMakeContextCurrent(window);

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    const char *version = (const char *)glGetString(GL_VERSION);
    fprintf(stdout, "OpenGL version: %s\n", version);

    glClearColor(0.0, 0.0f, 0.4f, 0.0f);
    do
    {
        glClearColor(1.0, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        sleep(1);
        glClearColor(0.0, 1.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        sleep(1);
        glfwPollEvents();
    }while( glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
            glfwWindowShouldClose(window) == 0);

    glfwTerminate();

    return 0;
}
