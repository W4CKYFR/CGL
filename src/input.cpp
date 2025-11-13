#include "cgl.hpp"
#include <string>
#include <GLFW/glfw3.h>

namespace cgl {
	GLFWwindow* Input::s_Window = nullptr;
	bool Input::s_KeyPressed = false;
	int Input::s_LastKey = -1;
	bool Input::s_ButtonPressed = false;
	int Input::s_LastButton = -1;
	bool Input::s_KeyReleased = false;
	bool Input::s_ButtonReleased = false;

	void Input::SetWindow(GLFWwindow* window) {
		s_Window = window;

		glfwSetKeyCallback(s_Window, Input::KeyCallback);
		glfwSetMouseButtonCallback(s_Window, Input::MouseButtonCallback);
	}

	void Input::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		if (action == GLFW_PRESS) {
			s_KeyPressed = true;
			s_LastKey = key;
			s_KeyReleased = false;
		}
		else if (action == GLFW_RELEASE) {
			s_KeyPressed = false;
			s_KeyReleased = true;
		}
	}

	void Input::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
		if (action == GLFW_PRESS) {
			s_ButtonPressed = true;
			s_LastButton = button;
			s_ButtonReleased = false;
		}
		else if (action == GLFW_RELEASE) {
			s_ButtonPressed = false;
			s_LastButton = -1;
			s_ButtonReleased = true;
		}
	}

	bool Input::IsKeyDown(Key key) {
		if (!s_Window) return false;
		return glfwGetKey(s_Window, static_cast<int>(key)) == GLFW_PRESS;
	}

	bool Input::IsKeyPressed(Key key) {
		if (s_KeyPressed && s_LastKey == static_cast<int>(key)) {
			s_KeyPressed = false;
			return true;
		}
		return false;
	}

	bool Input::IsKeyReleased(Key key) {
		if (s_KeyReleased && s_LastKey == static_cast<int>(key)) {
			s_KeyReleased = false;
			return true;
		}
		return false;
	}

	bool Input::IsMouseButtonDown(Mouse button) {
		if (!s_Window) return false;
		return glfwGetMouseButton(s_Window, static_cast<int>(button)) == GLFW_PRESS;
	}

	bool Input::IsMouseButtonPressed(Mouse button) {
		if (s_ButtonPressed && s_LastButton == static_cast<int>(button)) {
			s_ButtonPressed = false;
			return true;
		}
		else if (!s_Window) return false;
		return false;
	}

	bool Input::IsMouseButtonReleased(Mouse button) {
		if (s_ButtonReleased && s_LastButton == static_cast<int>(button)) {
			s_ButtonReleased = false;
			return true;
		}
		return false;
	}
}
