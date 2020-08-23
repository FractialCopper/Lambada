#include <stdexcept>
#include <iostream>

#include "playerEngine.h"	// OpenGL + ImGui

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <inttypes.h>
}

int main(int, char**)
{
	try {
		AVFormatContext* av_format_ctx = avformat_alloc_context();

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
