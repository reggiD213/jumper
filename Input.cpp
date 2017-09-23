#include "Input.h"

bool Input::keys[]{};

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
	keys[key] = action != GLFW_RELEASE;
}