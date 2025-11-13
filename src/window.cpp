#include "cgl.hpp"
#include <GLFW/glfw3.h>
#include <iostream>

namespace cgl {
	Window::Window(int width, int height, const std::string& title) {
		glfwInit();

		if (!glfwInit()) {
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

		glViewport(0, 0, width, height);

	}

	Window::~Window() {
		glfwDestroyWindow(handle);
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
}