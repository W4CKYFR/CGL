#include <glad/glad.h>
#include "cgl.hpp"
#include <GLFW/glfw3.h>
#include <iostream>
#include "stb_truetype.h"
#define NANOVG_GL3_IMPLEMENTATION
#include <nanovg.h>
#include <nanovg_gl.h>

namespace cgl {
	Window::Window(int width, int height, const std::string& title) : vg(nullptr), handle(nullptr) {
		bool initialized = glfwInit();

		if (!initialized) {
			std::cerr << "[CGL] Failed to initialize GLFW" << std::endl;
			return;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		handle = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		if (!handle) {
			std::cerr << "[CGL] Failed to create handle" << std::endl;
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(handle);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cerr << "[CGL] Failed to initialize GLAD" << std::endl;
			return;
		}

		int fbWidth, fbHeight;
		glfwGetFramebufferSize(handle, &fbWidth, &fbHeight);
		glViewport(0, 0, fbWidth, fbHeight);

		int flags = NVG_ANTIALIAS | NVG_STENCIL_STROKES;
		#ifdef _DEBUG
			flags |= NVG_DEBUG;
		#endif

		vg = nvgCreateGL3(flags);
		if (!vg) {
			std::cerr << "[CGL] Failed to initialize NanoVG" << std::endl;
			return;
		}
	}
		Window::~Window() {
			if (handle) {
				glfwMakeContextCurrent(handle);

				if (vg) {
					nvgDeleteGL3(vg);
					vg = nullptr;
				}

				glfwDestroyWindow(handle);
				handle = nullptr;
			}

			glfwTerminate();
		}

		bool Window::ShouldClose() const {
			return glfwWindowShouldClose(handle);
		}

		void Window::PollEvents() const {
			glfwPollEvents();
		}

		void Window::SwapBuffers() const {
			glfwSwapBuffers(handle);
		}

		void Window::clearColorBufferBit() const {
			glClear(GL_COLOR_BUFFER_BIT);
		}

		void Window::setColor(float Red, float Blue, float Green, float alpha) const {
			glClearColor(Red, Blue, Green, alpha);
		}

		GLFWwindow* Window::GetHandle() const {
			return handle;
		}

		void Window::Close() const {
			glfwSetWindowShouldClose(handle, true);
		}

		NVGcontext* Window::GetVGContext() const { return vg; }
}
