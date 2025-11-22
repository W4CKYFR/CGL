#include <nanovg.h>
#include "cgl.hpp"
#include <GLFW/glfw3.h>

namespace cgl {
	void Draw::BeginDraw(cgl::Window& window) {
		int w, h;
		glfwGetFramebufferSize(window.GetHandle(), &w, &h);

		NVGcontext* vg = window.GetVGContext();
		if (!vg) return;

		nvgBeginFrame(vg, w, h, 1.0f);
	}

	void Draw::EndDraw(cgl::Window& window) {
		NVGcontext* vg = window.GetVGContext();
		if (!vg) return;

		nvgEndFrame(vg);
	}
}