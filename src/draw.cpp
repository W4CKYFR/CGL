#include <nanovg.h>
#include "cgl.hpp"
#include <GLFW/glfw3.h>
#include <iostream>

namespace cgl {
	void Draw::BeginDraw(cgl::Window& window) {
		int w, h;

		glfwGetFramebufferSize(window.GetHandle(), &w, &h);

		NVGcontext* vg = window.GetVGContext();
		if (!vg) return;

		float wfloat = static_cast<float>(w);
		float hfloat = static_cast<float>(h);
		nvgBeginFrame(vg, wfloat, hfloat, 1.0f);
	}

	void Draw::EndDraw(cgl::Window& window) {
		NVGcontext* vg = window.GetVGContext();
		if (!vg) return;

		nvgEndFrame(vg);
	}
}