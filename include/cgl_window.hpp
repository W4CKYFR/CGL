#pragma once
#include <string>
#include <GLFW/glfw3.h>

namespace cgl {
	class Window {
	public:
		Window(int width, int height, const std::string& title);
		~Window();

		bool ShouldClose() const;
		void PollEvents() const;
		void SwapBuffers() const;
		void clearColorBufferBit() const;
		void setColor(float Red, float Blue, float Green, float aplha) const;
		GLFWwindow* GetHandle() const;
		void Close() const;

	private:
		GLFWwindow* handle;

	};
}