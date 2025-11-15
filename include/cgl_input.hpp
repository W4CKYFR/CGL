#pragma once
#include <string>
#include <GLFW/glfw3.h>
#include <unordered_map>

namespace cgl {
	enum class Key {
		Num0 = GLFW_KEY_0,
		Num1 = GLFW_KEY_1,
		Num2 = GLFW_KEY_2,
		Num3 = GLFW_KEY_3,
		Num4 = GLFW_KEY_4,
		Num5 = GLFW_KEY_5,
		Num6 = GLFW_KEY_6,
		Num7 = GLFW_KEY_7,
		Num8 = GLFW_KEY_8,
		Num9 = GLFW_KEY_9,
		A = GLFW_KEY_A,
		B = GLFW_KEY_B,
		C = GLFW_KEY_C,
		D = GLFW_KEY_D,
		E = GLFW_KEY_E,
		F = GLFW_KEY_F,
		G = GLFW_KEY_G,
		H = GLFW_KEY_H,
		I = GLFW_KEY_I,
		J = GLFW_KEY_J,
		K = GLFW_KEY_K,
		L = GLFW_KEY_L,
		M = GLFW_KEY_M,
		N = GLFW_KEY_N,
		O = GLFW_KEY_O,
		P = GLFW_KEY_P,
		Q = GLFW_KEY_Q,
		R = GLFW_KEY_R,
		S = GLFW_KEY_S,
		T = GLFW_KEY_T,
		U = GLFW_KEY_U,
		V = GLFW_KEY_V,
		W = GLFW_KEY_W,
		X = GLFW_KEY_X,
		Y = GLFW_KEY_Y,
		Z = GLFW_KEY_Z,
		Tab = GLFW_KEY_TAB,
		Backspace = GLFW_KEY_BACKSPACE,
		UpArrow = GLFW_KEY_UP,
		DownArrow = GLFW_KEY_DOWN,
		LeftArrow = GLFW_KEY_LEFT,
		RightArrow = GLFW_KEY_RIGHT,
		LeftControl = GLFW_KEY_LEFT_CONTROL,
		RightControl = GLFW_KEY_RIGHT_CONTROL,
		LeftShift = GLFW_KEY_LEFT_SHIFT,
		RightShift = GLFW_KEY_RIGHT_SHIFT,
		Escape = GLFW_KEY_ESCAPE,
		Space = GLFW_KEY_SPACE,
		Enter = GLFW_KEY_ENTER,
		CapsLock = GLFW_KEY_CAPS_LOCK,
		Delete = GLFW_KEY_DELETE,
		F1 = GLFW_KEY_F1,
		F2 = GLFW_KEY_F2,
		F3 = GLFW_KEY_F3,
		F4 = GLFW_KEY_F4,
		F5 = GLFW_KEY_F5,
		F6 = GLFW_KEY_F6,
		F7 = GLFW_KEY_F7,
		F8 = GLFW_KEY_F8,
		F9 = GLFW_KEY_F9,
		F10 = GLFW_KEY_F10,
		F11 = GLFW_KEY_F11,
		F12 = GLFW_KEY_F12
	};
	enum class Mouse {
		RightMouseButton = GLFW_MOUSE_BUTTON_RIGHT,
		LeftMouseButton = GLFW_MOUSE_BUTTON_LEFT,
		MiddleMouseButton = GLFW_MOUSE_BUTTON_MIDDLE,

	};
	class Input {
	public:
		static bool IsKeyDown(Key key);
		static bool IsKeyDown(const std::string& InputName);
		static bool IsMouseButtonDown(Mouse mouseButton);
		static bool IsMouseButtonDown(const std::string& InputName);
		static void SetWindow(GLFWwindow* window);
		static bool IsKeyPressed(Key key);
		static bool IsKeyPressed(const std::string& InputName);
		static bool IsKeyReleased(Key key);
		static bool IsKeyReleased(const std::string& InputName);
		static bool IsMouseButtonPressed(Mouse mouseButton);
		static bool IsMouseButtonPressed(const std::string& InputName);
		static bool IsMouseButtonReleased(Mouse mouseButton);
		static bool IsMouseButtonReleased(const std::string& InputName);
		static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		static void BindKeyInput(const std::string& InputName, Key);
		static void BindMouseInput(const std::string& MouseInputName, Mouse);

	private:
		static GLFWwindow* s_Window;
		static bool s_KeyPressed;
		static int s_LastKey;
		static bool s_ButtonPressed;
		static int s_LastButton;
		static bool s_KeyReleased;
		static bool s_ButtonReleased;
		static std::unordered_map<std::string, Key> s_KeyInputBindings;
		static std::unordered_map<std::string, Mouse> s_MouseInputBindings;
	};
}
