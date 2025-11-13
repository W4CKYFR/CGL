#pragma once
#include <string>
#include <GLFW/glfw3.h>

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
		W = GLFW_KEY_W,
		A = GLFW_KEY_A,
		S = GLFW_KEY_S,
		D = GLFW_KEY_D,
		E = GLFW_KEY_E,
		F = GLFW_KEY_F,
		R = GLFW_KEY_R,
		C = GLFW_KEY_C,
		Q = GLFW_KEY_Q,
		T = GLFW_KEY_T,
		Y = GLFW_KEY_Y,
		U = GLFW_KEY_U,
		I = GLFW_KEY_I,
		O = GLFW_KEY_O,
		P = GLFW_KEY_P,
		G = GLFW_KEY_G,
		H = GLFW_KEY_H,
		J = GLFW_KEY_J,
		K = GLFW_KEY_K,
		L = GLFW_KEY_L,
		Z = GLFW_KEY_Z,
		X = GLFW_KEY_X,
		V = GLFW_KEY_V,
		B = GLFW_KEY_B,
		N = GLFW_KEY_N,
		M = GLFW_KEY_M,
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
		CapsLock = GLFW_KEY_CAPS_LOCK
	};
	enum class Mouse {
		RightMouseButton = GLFW_MOUSE_BUTTON_RIGHT,
		LeftMouseButton = GLFW_MOUSE_BUTTON_LEFT,
		MiddleMouseButton = GLFW_MOUSE_BUTTON_MIDDLE,

	};
	class Input {
	public:
		static bool IsKeyDown(Key key);
		static bool IsMouseButtonDown(Mouse mouseButton);
		static void SetWindow(GLFWwindow* window);
		static bool IsKeyPressed(Key key);
		static bool IsKeyReleased(Key key);
		static bool IsMouseButtonPressed(Mouse mouseButton);
		static bool IsMouseButtonReleased(Mouse mouseButton);
		static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

	private:
		static GLFWwindow* s_Window;
		static bool s_KeyPressed;
		static int s_LastKey;
		static bool s_ButtonPressed;
		static int s_LastButton;
		static bool s_KeyReleased;
		static bool s_ButtonReleased;
	};
}