#include "cgl.hpp"
#include <nanovg.h>

namespace cgl {
    const Color Color::White{ 255, 255, 255, 255 };
    const Color Color::Black{ 0, 0, 0, 255 };
    const Color Color::Red{ 255, 0, 0, 255 };
    const Color Color::Green{ 0, 255, 0, 255 };
    const Color Color::Blue{ 0, 0, 255, 255 };

    Shape::Triangle::Triangle(NVGcontext* vg, Vector2 point1, Vector2 point2, Vector2 point3, Color color) : vg(vg), p1(point1), p2(point2), p3(point3), color(color) {}

    void Shape::Triangle::Draw() {
        if (!vg || !visible) return;

        nvgBeginPath(vg);
        nvgMoveTo(vg, p1.x, p1.y);
        nvgLineTo(vg, p2.x, p2.y);
        nvgLineTo(vg, p3.x, p3.y);
        nvgClosePath(vg);

        nvgFillColor(vg, nvgRGBA(color.r, color.g, color.b, color.a));
        nvgFill(vg);
    }

    void Shape::Triangle::SetPoints(Vector2 newP1, Vector2 newP2, Vector2 newP3) {
        p1 = newP1;
        p2 = newP2;
        p3 = newP3;
    }

    void Shape::Triangle::Show() { visible = true; }
    void Shape::Triangle::Hide() { visible = false; }

    Shape::Triangle Shape::DefaultTriangle(NVGcontext* vg, Color color) {
        return Shape::Triangle(
            vg,
            { 100, 100 },
            { 200, 100 },
            { 150, 200 },
            color);
    }

    Shape::Rectangle::Rectangle(NVGcontext* vg, Vector2 a, Vector2 b, Vector2 c, Vector2 d, Color color) : vg(vg), p1(a), p2(b), p3(c), p4(d), color(color) {}

    void Shape::Rectangle::Draw() {
        if (!vg || !visible) return;

        nvgBeginPath(vg);
        nvgMoveTo(vg, p1.x, p1.y);
        nvgLineTo(vg, p2.x, p2.y);
        nvgLineTo(vg, p3.x, p3.y);
        nvgLineTo(vg, p4.x, p4.y);
        nvgClosePath(vg);

        nvgFillColor(vg, nvgRGBA(color.r, color.g, color.b, color.a));
        nvgFill(vg);
    }

    void Shape::Rectangle::SetPoints(Vector2 newP1, Vector2 newP2, Vector2 newP3, Vector2 newP4) {
        p1 = newP1;
        p2 = newP2;
        p3 = newP3;
        p4 = newP4;
    }

    void Shape::Rectangle::Show() { visible = true; }
    void Shape::Rectangle::Hide() { visible = false; }

    Shape::Rectangle Shape::DefaultSquare(NVGcontext* vg, Color color) {
        return Shape::Rectangle(
            vg,
            { 100, 100 }, 
            { 200, 100 }, 
            { 200, 200 }, 
            { 100, 200 },
            color);
    }

}