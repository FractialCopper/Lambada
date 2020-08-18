#pragma once

// include OpenGL functionalities
#include <glad.h>  // Initialize with gladLoadGL()
#include <glfw3.h>

// [Win32] Our example includes a copy of glfw3.lib pre-compiled with VS2010 to maximize ease of testing and compatibility with old VS compilers.
// To link with VS2010-era libraries, VS2015+ requires linking with legacy_stdio_definitions.lib, which we do using this pragma.
// Your own project should not be affected, as you are likely to link with a newer binary of GLFW that is adequate for your version of Visual Studio.
#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

class GraphicEngine
{
public:
	GraphicEngine();
	~GraphicEngine();

	GLFWwindow* window;
	const char* glsl_version;

private:
	void gl_init();
};