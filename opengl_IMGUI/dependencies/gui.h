#pragma once

class PlayerEngine;

class Gui
{
public:
	Gui(PlayerEngine* eng);
	~Gui();

	PlayerEngine* engine;

	void demoDraw();
	void render();

private:
};