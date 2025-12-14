#pragma once
#include <vector>
#include <variant>
#include "cgl_shape.hpp"
#include "cgl_text.hpp"

namespace cgl {

	using DrawableVariant = std::variant <
		cgl::Shape::Triangle*,
		cgl::Shape::Rectangle*,
		cgl::Shape::Circle*,
		cgl::Text*
	>;

	class Layer {
	public:
		std::vector<DrawableVariant> drawables;

		template <typename T> 
		void Add(const T& drawable) {
			drawables.push_back(drawable);
		}

		void Draw();
		void Show();
		void Hide();
	};
}