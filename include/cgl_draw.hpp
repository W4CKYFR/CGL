#pragma once
#include "cgl_window.hpp"

namespace cgl {
	class Draw {
	public:
		static void BeginDraw(cgl::Window& window);
		static void EndDraw(cgl::Window& window);
	};
}