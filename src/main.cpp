#include "cgl.hpp"
#include <iostream>

int main() {
	float width = 800;
	float height = 600;
	cgl::Window window(width, height, "WackyMenu");

	cgl::Shape::Rectangle button = cgl::Shape::DefaultSquare(window.GetVGContext(), cgl::Color::Blue);

	cgl::Shape::Rectangle startButton = cgl::Shape::DefaultSquare(window.GetVGContext(), cgl::Color::Blue);

	startButton.Scale(2, 1);

	button.SetPosition(cgl::Position::BottomLeft(window));
	startButton.SetPosition(cgl::Position::Center(window));


	cgl::Font font(window.GetVGContext(), "C:\\Users\\Z2 G4\\Downloads\\Roboto\\Roboto-VariableFont_wdth,wght.ttf");

	cgl::Text button1text(window.GetVGContext(), font, "Quit", button.GetCenter(), 24, cgl::Color::White);
	cgl::Text startbuttonText(window.GetVGContext(), font, "Start", startButton.GetCenter(), 24, cgl::Color::White);

	cgl::Shape::Rectangle Player = cgl::Shape::DefaultSquare(window.GetVGContext(), cgl::Color::Red);
	cgl::Text text(window.GetVGContext(), font, "Player", cgl::Position::Center(window), 24, cgl::Color::White);

	cgl::Input::SetWindow(window.GetHandle());

	cgl::Color hoverBlue{ 0, 0, 255, 180 };

	cgl::Layer startLayer;

	startLayer.Add(&button);
	startLayer.Add(&button1text);
	startLayer.Add(&startButton);
	startLayer.Add(&startbuttonText);

	cgl::Layer gameLayer;

	gameLayer.Add(&Player);
	gameLayer.Add(&text);

	Player.SetPosition(cgl::Position::Center(window));

	bool Game = false;

	window.SetColor(cgl::Color::White);
	while (!window.ShouldClose()) {
		window.ClearColorBufferBit();
		window.PollEvents();

		cgl::Draw::BeginDraw(window);

		startLayer.Draw();

		if (button.IsMouseHovering()) {
			button.SetColor(hoverBlue);
			if (cgl::Input::IsMouseButtonPressed(cgl::Mouse::LeftMouseButton)) {
				window.Close();
			}
		}
		else if (startButton.IsMouseHovering()) {
			startButton.SetColor(hoverBlue);
			if (cgl::Input::IsMouseButtonPressed(cgl::Mouse::LeftMouseButton)) {
				startLayer.Hide();
				Game = true;
			}
		}
		else {
			button.SetColor(cgl::Color::Blue);
			startButton.SetColor(cgl::Color::Blue);
		}

		if (Game) {
			gameLayer.Draw();
			gameLayer.Show();
		}
		else {
			gameLayer.Hide();
		}

		text.SetPosition(Player.GetCenter());

		if (cgl::Input::IsKeyDown(cgl::Key::W)) {
			Player.MoveUp(1);
		}

		if (cgl::Input::IsKeyDown(cgl::Key::S)) {
			Player.MoveDown(1);
		}

		if (cgl::Input::IsKeyDown(cgl::Key::A)) {
			Player.MoveLeft(1);
		}

		if (cgl::Input::IsKeyDown(cgl::Key::D)) {
			Player.MoveRight(1);
		}

		if (cgl::Input::IsKeyPressed(cgl::Key::Escape)) {
			gameLayer.Hide();
			startLayer.Show();
			Game = false;
		}

		cgl::Draw::EndDraw(window);

		window.SwapBuffers();
	}
}