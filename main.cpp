#include <iostream>
#include <chrono> //for sleep
#include <thread>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Game.h"
#include "Input.h"

bool glfwSetup();
bool glewAndOpenGLSetup();

void error(const char* msg);
static void error_callback(int err, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

const int WIDTH = 1280, HEIGHT = 720;
int width, height;

GLFWwindow* window;

Game game;

int main(int argc, char *argv[])
{
	if (!glfwSetup())
		return -1;

	if (!glewAndOpenGLSetup())
		return -1;
	
	game.init(width, height);

	// Gameloop
	while (!glfwWindowShouldClose(window))
	{
		game.fps(glfwGetTime());
		glfwPollEvents();
		game.input();
		game.update();
		game.render();
		glfwSwapBuffers(window);

		// Simulate framedrops
		std::chrono::milliseconds timespan(16);
		std::this_thread::sleep_for(timespan);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

// Setup functions
bool glfwSetup()
{
	if (!glfwInit())
	{
		std::cerr << "Error initializing glfw!" << std::endl;
		return false;
	}
	glfwSetErrorCallback(error_callback);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, false);

	window = glfwCreateWindow(WIDTH, HEIGHT, "Jumper", nullptr, nullptr);
	if (!window)
	{
		std::cerr << "Error creating window!" << std::endl;
		return false;
	}
	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, Input::key_callback);

	return true;
}

bool glewAndOpenGLSetup()
{
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Error initializing glew!" << std::endl;
		return false;
	}
	// Discard glewInit() bug error msg.
	glGetError();

	// Get size from Framebuffer for high dpi displays
	
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	//glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return true;
}

// Callbacks
static void error_callback(int err, const char* description)
{
	std::cerr << description << std::endl;
}