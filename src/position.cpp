#include "cgl_position.hpp"
#include "cgl_window.hpp"
#include "cgl_vector.hpp"

namespace cgl {
	constexpr float margin = 50.0f;

	cgl::Vector2 Position::Center(const Window& window) {
		return { window.GetWidth() / 2.0f, window.GetHeight() / 2.0f };
	}

	cgl::Vector2 Position::TopLeft(const Window& window) {
		return { margin, margin };
	}

	cgl::Vector2 Position::BottomRight(const Window& window) {
		return { window.GetWidth() - margin, window.GetHeight() - margin };
	}

	cgl::Vector2 Position::TopRight(const Window& window) {
		return { window.GetWidth() - margin, margin };
	}

	cgl::Vector2 Position::BottomLeft(const Window& window) {
		return { margin, window.GetHeight() - margin };
	}

	cgl::Vector2 Position::Left(const Window& window) {
		return { margin, window.GetHeight() / 2.0f };
	}

	cgl::Vector2 Position::Right(const Window& window) {
		return { window.GetWidth() - margin, window.GetHeight() / 2.0f };
	}
}