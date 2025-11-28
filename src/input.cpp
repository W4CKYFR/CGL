#include "cgl.hpp"
#include <string>
#include <GLFW/glfw3.h>
#include <unordered_map>

namespace cgl {
	GLFWwindow* Input::s_Window = nullptr;
	bool Input::s_KeyPressed = false;
	int Input::s_LastKey = -1;
	bool Input::s_ButtonPressed = false;
	int Input::s_LastButton = -1;
	bool Input::s_KeyReleased = false;
	bool Input::s_ButtonReleased = false;
	std::unordered_map<std::string, Key> Input::s_KeyInputBindings;
	std::unordered_map<std::string, Mouse> Input::s_MouseInputBindings;
	double Input::mouseX = 0.0;
	double Input::mouseY = 0.0;

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

	bool Input::IsKeyDown(const std::string& InputName) {
		auto it = s_KeyInputBindings.find(InputName);
		if (it == s_KeyInputBindings.end()) {
			return false;
		}

		return IsKeyDown(it->second);
	}

	bool Input::IsKeyPressed(Key key) {
		if (s_KeyPressed && s_LastKey == static_cast<int>(key)) {
			s_KeyPressed = false;
			return true;
		}
		return false;
	}

	bool Input::IsKeyPressed(const std::string& InputName) {
		auto it = s_KeyInputBindings.find(InputName);
		if (it == s_KeyInputBindings.end()) {
			return false;
		}

		return IsKeyPressed(it->second);
	}

	bool Input::IsKeyReleased(Key key) {
		if (s_KeyReleased && s_LastKey == static_cast<int>(key)) {
			s_KeyReleased = false;
			return true;
		}
		return false;
	}

	bool Input::IsKeyReleased(const std::string& InputName) {
		auto it = s_KeyInputBindings.find(InputName);
		if (it == s_KeyInputBindings.end()) {
			return false;
		}

		return IsKeyReleased(it->second);
	}

	bool Input::IsMouseButtonDown(Mouse mouseButton) {
		if (!s_Window) return false;
		return glfwGetMouseButton(s_Window, static_cast<int>(mouseButton)) == GLFW_PRESS;
	}

	bool Input::IsMouseButtonDown(const std::string& MouseInputName) {
		auto it = s_MouseInputBindings.find(MouseInputName);
		if (it == s_MouseInputBindings.end())
			return false;

		return IsMouseButtonDown(it->second);
	}

	bool Input::IsMouseButtonPressed(Mouse mouseButton) {
		if (s_ButtonPressed && s_LastButton == static_cast<int>(mouseButton)) {
			s_ButtonPressed = false;
			return true;
		}
		return false;
	}

	bool Input::IsMouseButtonPressed(const std::string& MouseInputName) {
		auto it = s_MouseInputBindings.find(MouseInputName);
		if (it == s_MouseInputBindings.end())
			return false;

		return IsMouseButtonPressed(it->second);
	}

	bool Input::IsMouseButtonReleased(Mouse mouseButton) {
		if (s_ButtonReleased && s_LastButton == static_cast<int>(mouseButton)) {
			s_ButtonReleased = false;
			return true;
		}
		return false;
	}

	bool Input::IsMouseButtonReleased(const std::string& InputName) {
		auto it = s_MouseInputBindings.find(InputName);
		if (it == s_MouseInputBindings.end())
			return false;

		return IsMouseButtonReleased(it->second);
	}

	void Input::BindKeyInput(const std::string& InputName, Key key) {
		s_KeyInputBindings[InputName] = key;
	}

	void Input::BindMouseInput(const std::string& MouseInputName, Mouse mouseButton) {
		s_MouseInputBindings[MouseInputName] = mouseButton;
	}

	cgl::Vector2 Input::GetMousePosition() {
		glfwGetCursorPos(s_Window, &mouseX, &mouseY);
		return cgl::Vector2((float)mouseX, (float)mouseY);
	}

	double Input::GetMouseX() {
		return GetMousePosition().x;
	}

	double Input::GetMouseY() {
		return GetMousePosition().y;
	}
}