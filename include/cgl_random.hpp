#pragma once
#include "cgl_position.hpp"
#include "cgl_vector.hpp"
#include "cgl_window.hpp"

namespace cgl {
	struct Random {
		template<typename T>
		static T Get();

		static Vector2 GetVector(const Window& window);
	};

	template<>
	Vector2 Random::Get<Vector2>();

	template<>
	Color Random::Get<Color>();
}