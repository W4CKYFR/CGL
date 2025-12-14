#include "cgl_image.hpp"
#include <nanovg.h>

namespace cgl {
	Image::Image(NVGcontext* vg, const char* path, int flags, float xpos, float ypos, float w, float h) : vg(vg), x(xpos), y(ypos), width(w), height(h) {
		this->image = nvgCreateImage(vg, path, flags);
	}

	void Image::Draw() {
		if (!visible) return;
		NVGpaint paint = nvgImagePattern(vg, x, y, width, height, 0.0f, image, 1.0f);
		nvgBeginPath(vg);
		nvgRect(vg, x, y, width, height);
		nvgFillPaint(vg, paint);
		nvgFill(vg);
	}

	void Image::Show() {
		visible = true;
	}

	void Image::Hide() {
		visible = false;
	}

	void Image::MoveUp(float moveAmount) {
		y -= moveAmount;
	}

	void Image::MoveDown(float moveAmount) {
		y += moveAmount;
	}

	void Image::MoveLeft(float moveAmount) {
		x -= moveAmount;
	}

	void Image::MoveRight(float moveAmount) {
		x += moveAmount;
	}
}