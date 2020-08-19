#pragma once

struct GLFWwindow;
class Gui;

class PlayerEngine
{
public:
	PlayerEngine();
	~PlayerEngine();

	GLFWwindow* window;
	const char* glsl_version;

	Gui* gui;

	void loop();
};