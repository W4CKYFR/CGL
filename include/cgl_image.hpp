#pragma once
#include <nanovg.h>

namespace cgl {
    class Image {
    public:
        Image(NVGcontext* vg, const char* path, int flags, float x, float y, float width, float height);
        void Draw();
        void Show();
        void Hide();

        void MoveUp(float moveAmount);
        void MoveDown(float moveAmount);
        void MoveLeft(float moveAmount);
        void MoveRight(float moveAmount);

    private:
        NVGcontext* vg;
        int image;
        float x, y;
        float width, height;
        bool visible = true;
    };
}