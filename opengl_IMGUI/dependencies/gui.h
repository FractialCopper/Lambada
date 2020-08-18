#pragma once

// dear imgui: standalone example application for GLFW + OpenGL 3, using programmable pipeline
// If you are new to dear imgui, see examples/README.txt and documentation at the top of imgui.cpp.
// (GLFW is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)
//dumbcomment
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

class GraphicEngine;

class Gui
{
public:
	Gui(GraphicEngine* eng);
	~Gui();

	GraphicEngine* engine;

	void demoDraw();
	void render();

private:
	void imgui_init();
};