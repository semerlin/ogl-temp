#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

void add_shader(GLuint shader_program, const string &shader_text, GLenum shader_type)
{
    GLuint shader_obj = glCreateShader(shader_type);
    const GLchar *p[1];
    p[0] = shader_text.c_str();
    GLint lengths[1];
    lengths[0] = shader_text.size();
    glShaderSource(shader_obj, 1, p, lengths);
    GLint success;
    glCompileShader(shader_obj);
    glGetShaderiv(shader_obj, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        GLchar info[1024];
        glGetShaderInfoLog(shader_obj, 1024, NULL, info);
        cout << "complier shader failed: " << info << endl;
        exit(EXIT_FAILURE);
    }
    glAttachShader(shader_program, shader_obj);
}

void read_file(const string &name, string &content)
{
    ifstream file(name.c_str(), ifstream::in);
    if (!file.is_open())
    {
        cout << "read file \"" << name << "\"" << "failed" << endl;
        content = "";
        return ;
    }

    stringstream sstr;
    sstr << file.rdbuf();
    content = sstr.str();

    file.close();
}

void compiler_shaders(void)
{
    GLuint shader_program = glCreateProgram();
    string vs_buf, fs_buf;
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

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    GLFWwindow *window = glfwCreateWindow(640, 480, "test", NULL, NULL);
    if (NULL == window)
    {
        cout << "create window failed\n" << endl;
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

    //create vao
    GLuint vao_id;
    glGenVertexArrays(1, &vao_id);
    glBindVertexArray(vao_id);

    //create vbo
    GLfloat vertex_buffer[] = {-1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f};
    GLuint vbo_id;
    glGenBuffers(1, &vbo_id);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer), vertex_buffer, GL_STATIC_DRAW);

    //set vertex attibute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    compiler_shaders();
    do
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(vao_id);
        glEnableVertexAttribArray(0);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glDisableVertexAttribArray(0);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }while( glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
            glfwWindowShouldClose(window) == 0);

    glfwTerminate();

    return 0;
}

