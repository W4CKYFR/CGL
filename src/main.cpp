#include "cgl.hpp"
#include <iostream>

int main() {
	cgl::Window window(800, 600, "Window Name");

	cgl::Text text(window.GetVGContext(), "Roboto", "Hello World", 300, 300, 24);

	cgl::Shape::Triangle triangle = cgl::Shape::DefaultTriangle(window.GetVGContext(), cgl::Color::Red);

	text.LoadFont("Roboto", "C:\\Users\\Z2 G4\\Downloads\\Roboto\\Roboto-VariableFont_wdth,wght.ttf");

	cgl::Input::SetWindow(window.GetHandle());
	window.SetColor(0.0f, 0.0f, 0.0f, 1.0f);
    while (!window.ShouldClose()) {
        window.ClearColorBufferBit();
        window.PollEvents();

		cgl::Draw::BeginDraw(window);

		triangle.Draw();
		text.Draw();
		text.SetText("What's up");

		if (cgl::Input::IsKeyDown(cgl::Key::W)) {
			triangle.MoveUp(1);
		}

		if (cgl::Input::IsKeyDown(cgl::Key::S)) {
			triangle.MoveDown(1);
		}

		if (cgl::Input::IsKeyDown(cgl::Key::A)) {
			triangle.MoveLeft(1);
		}

		if (cgl::Input::IsKeyDown(cgl::Key::D)) {
			triangle.MoveRight(1);
		}

		cgl::Draw::EndDraw(window);

		window.SwapBuffers();
    }
}