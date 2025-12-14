#pragma once
#include <string>
#include <nanovg.h>
#include "cgl_vector.hpp"
#include "cgl_color.hpp"

namespace cgl {

    class Font {
    public:
        Font(NVGcontext* vg, const std::string& fontPath);

        const char* GetVGName() const;
        bool IsLoaded() const;

    private:
        NVGcontext* vg;
        std::string vgName;
        bool loaded = false;
        static inline uint32_t idCounter = 0;
    };

    class Text {
    public:
        Text(NVGcontext* vg, const Font& font, std::string text, Vector2 pos, float size, Color color);

        void Draw() const;
        void SetText(std::string newText);
        void SetPosition(Vector2 newPos);
        void SetSize(float newSize);
        void Show();
        void Hide();
        void SetColor(Color newColor);
        void MoveUp(float amt);
        void MoveDown(float amt);
        void MoveLeft(float amt);
        void MoveRight(float amt);

    private:
        NVGcontext* vg;
        const Font* font;
        std::string text;
        Vector2 position;
        float size;
        Color color;
        bool visible = true;
    };

}