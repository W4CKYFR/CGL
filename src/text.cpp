#include <glad/glad.h>
#include "cgl.hpp"
#include <GLFW/glfw3.h>
#include <iostream>
#include "stb_truetype.h"
#include <nanovg.h>

namespace cgl {
	Text::Text(NVGcontext* context, const char* fontName, const char* text, float xpos, float ypos, float s) : vg(context), fontName(fontName), text(text), x(xpos), y(ypos), size(s) {}

	void Text::LoadFont(const char* fontName, const char* fontPath) {
		int fontRes = nvgCreateFont(vg, fontName, fontPath);
		if (fontRes == -1) {
			std::cerr << "[CGL] Failed to load font" << std::endl;
			fontLoaded = false;
		}
		else {
			fontLoaded = true;
		}
	}

	void Text::Draw() const{
		if (!visible) {
			return;
		}

		if (!fontLoaded) {
			std::cerr << "[CGL] Attempting to draw text with font '" << fontName << "' that hasn't been loaded." << std::endl;
			return; 
		}

		nvgFontSize(vg, size);
		nvgFontFace(vg, fontName);
		nvgFillColor(vg, nvgRGB(255, 255, 255));

		nvgText(vg, x, y, text.c_str(), nullptr);
	}

	void Text::SetText(std::string newText) {
		text = newText;
	}

	void Text::SetSize(float newSize) {
		size = newSize;
	}

	void Text::SetPosition(float newX, float newY) {
		x = newX;
		y = newY;
	}

	void Text::Show() {
		visible = true;
	}

	void Text::Hide() {
		visible = false;
	}
}