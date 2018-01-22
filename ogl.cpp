/************************************************************************
 * File Name: ogl.c
 * Author: HuangYang
 * Mail: elious.huang@gmail.com
 * Created Time: Sun 19 Nov 2017 09:13:37 PM CST
 ************************************************************************/
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glxext.h>
#include <GL/glext.h>

using namespace std;

void add_shader(GLuint shader_program, const char *shader_text, GLenum shader_type)
{
    GLuint shader_obj = glCreateShader(shader_type);
    const GLchar *p[1];
    p[0] = shader_text;
    GLint lengths[1];
    lengths[0] = strlen(shader_text);
    glShaderSource(shader_obj, 1, p, lengths);
    GLint success;
    glCompileShader(shader_obj);
    glGetShaderiv(shader_obj, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        GLchar info[1024];
        glGetShaderInfoLog(shader_obj, 1024, NULL, info);
        cout << "compiler shader error: n" << info << endl;
        exit(EXIT_FAILURE);
    }
    glAttachShader(shader_program, shader_obj);
}

void read_file(const char *name, char *buf)
{
#if 0
    FILE *fp;
    char data;
    fp = fopen(name, "r");
    while ((data = fgetc(fp)) != EOF)
    {
        *buf ++ = data;
    }
#endif
}

void compiler_shaders(void)
{
    GLuint shader_program = glCreateProgram();
    char vs_buf[512], fs_buf[512];
    read_file("./shader.vs", vs_buf);
    read_file("./shader.fs", fs_buf);

    add_shader(shader_program, vs_buf, GL_VERTEX_SHADER);
    add_shader(shader_program, fs_buf, GL_FRAGMENT_SHADER);

    glLinkProgram(shader_program);
    glValidateProgram(shader_program);
    glUseProgram(shader_program);
}

int main(int argc, char **argv)
{
    if (!glfwInit())
    {
        fprintf(stderr, "init glfw failed\n");
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(640, 480, "test", NULL, NULL);
    if (NULL == window)
    {
        fprintf(stderr, "create window failed\n");
        return -1;
    }

    glfwMakeContextCurrent(window);

    const char *version = glGetString(GL_VERSION);
    fprintf(stdout, "version = %s\n", version);

    GLfloat vertex_buffer[] = {-1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f};

    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer), vertex_buffer, GL_STATIC_DRAW);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    compiler_shaders();
    do
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDisableVertexAttribArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }while( glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
            glfwWindowShouldClose(window) == 0);

    glfwTerminate();

    return 0;
}
