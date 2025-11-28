#pragma once
#include <string>
#include <nanovg.h>
#include <GLFW/glfw3.h>

namespace cgl {
    class Text {
    public:
        Text(NVGcontext* context, const char* fontName, const char* text, float x, float y, float size);

        void LoadFont(const char* fontName, const char* fontPath);

        void Draw() const;

        void SetText(std::string newText);
        void SetPosition(float newX, float newY);
        void SetSize(float newSize);
        void Show();
        void Hide();

    private:
        const char* fontName;
        std::string text;
        float x, y;
        float size;
        NVGcontext* vg;
        bool fontLoaded = false;
        bool visible = true;
    };
}
