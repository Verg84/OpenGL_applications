#include"declarations.h"


void init(GLFWwindow* window)
{
	renderer = CreateShaderProgram();
	glGenVertexArrays(VAOs, VAO);
	glBindVertexArray(VAO[0]);
}
void display(GLFWwindow* window, double ctime)
{
	glClearColor(.2, 0.7, 0.4, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(30.0f);
	glUseProgram(renderer);
	glDrawArrays(GL_POINTS, 0, 1);
}

int main()
{
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	GLFWwindow* window = glfwCreateWindow(600, 600, "DRAW A POINT", NULL, NULL);
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK)
	{
		exit(EXIT_FAILURE);
	}
	glfwSwapInterval(1);

	init(window);

	while (!glfwWindowShouldClose(window))
	{
		display(window, glfwGetTime());
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
	return 0;
}