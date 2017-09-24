#include "Input.h"

bool Input::keys[]{};
bool Input::keysProcessed[]{};

Input::Input()
{
}


Input::~Input()
{
}

void Input::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	//keys[key] = action != GLFW_RELEASE;


	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			keys[key] = GL_TRUE;
		else if (action == GLFW_RELEASE)
		{
			keys[key] = GL_FALSE;
			keysProcessed[key] = GL_FALSE;
		}
	}
}