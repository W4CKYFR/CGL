#pragma once
#include "cgl_vector.hpp"
#include "cgl_window.hpp"

namespace cgl {
	struct Position {
		static cgl::Vector2 Center(const cgl::Window& window);
		static cgl::Vector2 TopLeft(const cgl::Window& window);
		static cgl::Vector2 BottomRight(const cgl::Window& window);
		static cgl::Vector2 TopRight(const cgl::Window& window);
		static cgl::Vector2 BottomLeft(const cgl::Window& window);
		static cgl::Vector2 Left(const cgl::Window& window);
		static cgl::Vector2 Right(const cgl::Window& window);
	};
}