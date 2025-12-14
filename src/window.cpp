#include <glad/glad.h>
#include "cgl.hpp"
#include <GLFW/glfw3.h>
#include <iostream>
#include "stb_truetype.h"
#define NANOVG_GL3_IMPLEMENTATION
#include <nanovg.h>
#include <nanovg_gl.h>
#include <chrono>
#include <thread>

namespace cgl {
	std::chrono::steady_clock::time_point Window::lastTime;
	double Window::FPS = 0.0;
	double Window::deltaTime = 0.0;

	Window::Window(int width, int height, const std::string& title) : rWidth(width), rHeight(height),  vg(nullptr), handle(nullptr) {
		bool initialized = glfwInit();
		lastTime = std::chrono::high_resolution_clock::now();

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
			auto currentTime = std::chrono::high_resolution_clock::now();
			deltaTime = std::chrono::duration<double>(currentTime - lastTime).count();

			if (deltaTime > 0)
				FPS = 1.0 / deltaTime;

			glfwPollEvents();

			lastTime = std::chrono::high_resolution_clock::now();
		}

		void Window::SwapBuffers() const {
			glfwSwapBuffers(handle);
		}

		void Window::ClearColorBufferBit() const {
			glClear(GL_COLOR_BUFFER_BIT);
		}

		void Window::SetColor(const Color& c) const {
			glClearColor(c.r / 255.0f, c.g / 255.0f, c.b / 255.0f, c.a / 255.0f);
		}

		GLFWwindow* Window::GetHandle() const {
			return handle;
		}

		void Window::Close() const {
			glfwSetWindowShouldClose(handle, true);
		}

		NVGcontext* Window::GetVGContext() const { return vg; }

		double Window::GetFPS() const { return FPS; }
		double Window::GetDeltaTime() const { return deltaTime; }

		int Window::GetWidth() const { return rWidth; }
		int Window::GetHeight() const { return rHeight; }
}