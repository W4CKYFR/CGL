#pragma once
#include "cgl_vector.hpp"

namespace cgl {
	class Camera {
	public:
		Camera();

		void setPosition(const Vector2 pos) { position = pos; }
		void move(const Vector2& delta) { position += delta; }

		void setZoom(float z) { zoom = z; }
		void addZoom(float amount) { zoom += amount; }
	private:
		Vector2 position;
		float zoom = 1.0f;
	};
}