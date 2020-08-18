#include <stdexcept>
#include <iostream>

#include "graphicEngine.h"	// OpenGL
#include "gui.h"			// ImGui

int main(int, char**)
{
	try
	{
		// OpenGL & ImGui - init & binding
		GraphicEngine* gl_engine = new GraphicEngine();
		Gui* gui = new Gui(gl_engine);

		// Main loop
		while (!glfwWindowShouldClose(gl_engine->window))
		{
			gui->demoDraw();	// draw demo examples from imgui github
			gui->render();

			glfwSwapBuffers(gl_engine->window);
		}

		// cleanup
		delete gl_engine;
		delete gui;
	}
	catch (std::runtime_error err)
	{
		std::cout << err.what();
		return 1;
	}

	return 0;
}
