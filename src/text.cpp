#include <glad/glad.h>
#include "cgl.hpp"
#include "stb_truetype.h"
#include <iostream>
#include <nanovg.h>

namespace cgl {


    Text::Text(NVGcontext* vg, const Font& font, std::string text, Vector2 pos, float size, Color color)
        : vg(vg), font(&font), text(std::move(text)), position(pos), size(size), color(color) {
    }

    void Text::Draw() const {
        if (!visible || !font || !font->IsLoaded()) return;

        nvgFontSize(vg, size);
        nvgFontFace(vg, font->GetVGName());
        nvgFillColor(vg, nvgRGBA(color.r, color.g, color.b, color.a));
        nvgTextAlign(vg, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
        nvgText(vg, position.x, position.y, text.c_str(), nullptr);
    }

    void Text::SetText(std::string newText) { text = newText; }
    void Text::SetSize(float newSize) { size = newSize; }
    void Text::SetPosition(Vector2 newPos) { position.x = newPos.x; position.y = newPos.y; }
    void Text::Show() { visible = true; }
    void Text::Hide() { visible = false; }
    void Text::SetColor(Color newColor) { color = newColor; }
    void Text::MoveUp(float moveAmount) { position.y -= moveAmount; }
    void Text::MoveDown(float moveAmount) { position.y += moveAmount; }
    void Text::MoveLeft(float moveAmount) { position.x -= moveAmount; }
    void Text::MoveRight(float moveAmount) { position.x += moveAmount; }

    Font::Font(NVGcontext* vg, const std::string& fontPath) : vg(vg) {
        vgName = "cgl_font_" + std::to_string(idCounter++);
        int res = nvgCreateFont(vg, vgName.c_str(), fontPath.c_str());
        if (res == -1) {
            std::cerr << "[CGL] Failed to load font: " << fontPath << "\n";
            loaded = false;
        }
        else {
            loaded = true;
        }
    }

    const char* Font::GetVGName() const { return vgName.c_str(); }
    bool Font::IsLoaded() const { return loaded; }

}
