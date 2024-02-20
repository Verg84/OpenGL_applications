#pragma once
#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include<iostream>

#define VAOs 1

GLuint renderer;
GLuint VAO[VAOs];

GLuint CreateShaderProgram()
{
	const char* vshaderSRC =
		"#version 330 \n"
		"void main()\n"
		"{\n"
		"	gl_Position=vec4(0.0,0.0,0.0,1.0);\n"
		"}\n";
	const char* fShaderSRC =
		"#version 330 \n"
		"out vec4 Color;"
		"void main()\n"
		"{\n"
		"	Color=vec4(0.0,0.0,1.0,1.0f);\n"
		"}\n";
	GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vShader, 1, &vshaderSRC, NULL);
	glCompileShader(vShader);
	int status;
	char infoLog[512];
	glGetShaderiv(vShader, GL_COMPILE_STATUS, &status);
	if (!status)
	{
		glGetShaderInfoLog(vShader, 512, NULL, infoLog);
		std::cout << "\t *** vertex shader::" << infoLog << std::endl;
	}
	std::cout << "\t *** vertex shader::OK ***" << std::endl;

	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fShader,1,&fShaderSRC, NULL);
	glCompileShader(fShader);
	glGetShaderiv(fShader, GL_COMPILE_STATUS, &status);
	if (!status)
	{
		glGetShaderInfoLog(fShader, 512, NULL, infoLog);
		std::cout << "\t *** fragment shader::" << infoLog << std::endl;
	}
	std::cout << "\t *** fragment shader::OK ***" << std::endl;


	GLuint prog = glCreateProgram();
	glAttachShader(prog, vShader);
	glAttachShader(prog, fShader);
	glLinkProgram(prog);
	glGetProgramiv(prog, GL_LINK_STATUS, &status);
	if (!status)
	{
		glGetProgramInfoLog(prog, 512, NULL, infoLog);
		std::cout << "\t **** Program Link Failed::" << infoLog << std::endl;
	}
	std::cout << "\n\t *** program created ***" << std::endl;
	return prog;
}
