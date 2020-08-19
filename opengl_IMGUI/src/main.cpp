#include <stdexcept>
#include <iostream>

#include "playerEngine.h"	// OpenGL + ImGui

int main(int, char**)
{
	try {
		PlayerEngine e;
		e.loop();
		return 0;
	}
	catch (std::runtime_error err)
	{
		std::cout << err.what() << '\n';
		return 1;
	}
}
