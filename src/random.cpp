#include "cgl.hpp"
#include <cstdlib>

namespace cgl {
	template<>
	Vector2 Random::Get<Vector2>() {
		return {
			(float)rand() / RAND_MAX * 2.f - 1.f,
			(float)rand() / RAND_MAX * 2.f - 1.f
		};
	}

	Vector2 Random::GetVector(const Window& window) {
		return {
			static_cast<float>(rand() % window.GetWidth()),
			static_cast<float>(rand() % window.GetHeight())
		};
	}

	template<>
	Color Random::Get<Color>() {
		return {
			(unsigned char)(rand() % 256),
			(unsigned char)(rand() % 256),
			(unsigned char)(rand() % 256),
			255
		};
	}
}