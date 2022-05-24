/*#include "wt/glfw_wrapper.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <glad/glad.h>

int main()
{
    ax::wt::window_t window = ax::wt::window_t(640, 480, "Hello World");

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        std::cout << "Failed to load OpenGL" << std::endl;
        return -1;
    }

    const auto vs_file_path = "res/shaders/triangle.vs";
    const auto fs_file_path = "res/shaders/triangle.fs";

    std::string vs_code;
    std::string fs_code;

    try{
        std::ifstream vs_file(vs_file_path);
        std::ifstream fs_file(fs_file_path);
        std::stringstream vs_stream, fs_stream;
        vs_stream << vs_file.rdbuf();
        fs_stream << fs_file.rdbuf();

        vs_file.close();
        fs_file.close();

        const auto vs_source = vs_stream.str();
        const auto fs_source = fs_stream.str();

    }catch(const std::exception& e){
        std::cout << "fgf" << std::endl;
        std::cerr << e.what() << std::endl;
        return -1;
    }

    auto vs_code_c_str = vs_code.c_str();
    auto fs_code_c_str = fs_code.c_str();

    GLuint vs,fs, program;
    GLint success;
    GLchar infoLog[512];

    vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vs_code_c_str, nullptr);
    glCompileShader(vs);
    glGetShaderiv(vs, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vs, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fs_code_c_str, nullptr);
    glCompileShader(fs);
    glGetShaderiv(fs, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fs, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    program = glCreateProgram();
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vs);
    glDeleteShader(fs);

    glUseProgram(program);

    while (!window.should_close())
    {
        window.swap_buffers();
        glfwPollEvents();
    }

    return 0;
}*/
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
    std::cout << "main\n";

    return 0;
}