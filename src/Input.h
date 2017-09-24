#pragma once

#include <GLFW/glfw3.h>

class Input
{
public:
	static bool keys[1024];
	static bool keysProcessed[1024];

	Input();
	~Input();

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

