#include "cgl.hpp"
#include <nanovg.h>

namespace cgl {

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

    void Shape::Triangle::SetColor(Color newColor) {
        color = newColor;
    }

    Shape::Triangle Shape::DefaultTriangle(NVGcontext* vg, Color color) {
        return Shape::Triangle(
            vg,
            { 100, 100 },
            { 200, 100 },
            { 150, 200 },
            color);
    }

    void Shape::Triangle::MoveUp(float moveAmount) {
        p1.y -= moveAmount;
        p2.y -= moveAmount;
        p3.y -= moveAmount;
    }

    void Shape::Triangle::MoveDown(float moveAmount) {
        p1.y += moveAmount;
        p2.y += moveAmount;
        p3.y += moveAmount;
    }

    void Shape::Triangle::MoveLeft(float moveAmount) {
        p1.x -= moveAmount;
        p2.x -= moveAmount;
        p3.x -= moveAmount;
    }

    void Shape::Triangle::MoveRight(float moveAmount) {
        p1.x += moveAmount;
        p2.x += moveAmount;
        p3.x += moveAmount;
    }

    void Shape::Triangle::SetPosition(Vector2 newCenter) {
        Vector2 delta = newCenter - GetCenter();
        p1 += delta;
        p2 += delta;
        p3 += delta;
    }

    bool Shape::Triangle::IsMouseHovering() {
        Vector2 mousePosition = Input::GetMousePosition();

        Vector2 A = p1;
        Vector2 B = p2;
        Vector2 C = p3;

        Vector2 v0 = { C.x - A.x, C.y - A.y };
        Vector2 v1 = { B.x - A.x, B.y - A.y };
        Vector2 v2 = { mousePosition.x - A.x, mousePosition.y - A.y };

        float dot00 = v0.x * v0.x + v0.y * v0.y;
        float dot01 = v0.x * v1.x + v0.y * v1.y;
        float dot02 = v0.x * v2.x + v0.y * v2.y;
        float dot11 = v1.x * v1.x + v1.y * v1.y;
        float dot12 = v1.x * v2.x + v1.y * v2.y;

        float invDenom = 1.0f / (dot00 * dot11 - dot01 * dot01);
        float u = (dot11 * dot02 - dot01 * dot12) * invDenom;
        float v = (dot00 * dot12 - dot01 * dot02) * invDenom;

        return (u >= 0) && (v >= 0) && (u + v <= 1);
    }

    void Shape::Triangle::Scale(float scaleX, float scaleY) {
        Vector2 center = GetCenter();

        p1 = Vector2(center.x + (p1.x - center.x) * scaleX,
            center.y + (p1.y - center.y) * scaleY);
        p2 = Vector2(center.x + (p2.x - center.x) * scaleX,
            center.y + (p2.y - center.y) * scaleY);
        p3 = Vector2(center.x + (p3.x - center.x) * scaleX,
            center.y + (p3.y - center.y) * scaleY);
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

    void Shape::Rectangle::SetColor(Color newColor) {
        color = newColor;
    }

    Shape::Rectangle Shape::DefaultSquare(NVGcontext* vg, Color color) {
        return Shape::Rectangle(
            vg,
            { 100, 100 }, 
            { 200, 100 }, 
            { 200, 200 }, 
            { 100, 200 },
            color);
    }

    void Shape::Rectangle::MoveUp(float moveAmount) {
        p1.y -= moveAmount;
        p2.y -= moveAmount;
        p3.y -= moveAmount;
        p4.y -= moveAmount;
    }

    void Shape::Rectangle::MoveDown(float moveAmount) {
        p1.y += moveAmount;
        p2.y += moveAmount;
        p3.y += moveAmount;
        p4.y += moveAmount;
    }

    void Shape::Rectangle::MoveLeft(float moveAmount) {
        p1.x -= moveAmount;
        p2.x -= moveAmount;
        p3.x -= moveAmount;
        p4.x -= moveAmount;
    }

    void Shape::Rectangle::MoveRight(float moveAmount) {
        p1.x += moveAmount;
        p2.x += moveAmount;
        p3.x += moveAmount;
        p4.x += moveAmount;
    }

    void Shape::Rectangle::SetPosition(Vector2 newCenter) {
        Vector2 delta = newCenter - GetCenter();
        p1 += delta;
        p2 += delta;
        p3 += delta;
        p4 += delta;
    }

    bool Shape::Rectangle::IsMouseHovering() {
        Vector2 mousePosition = Input::GetMousePosition();

        float left = p1.x;
        float right = p3.x;
        float top = p1.y;
        float bottom = p3.y;

        return mousePosition.x >= left && mousePosition.x <= right &&
            mousePosition.y >= top && mousePosition.y <= bottom;
    }

    void Shape::Rectangle::Scale(float scaleX, float scaleY) {
        Vector2 center = GetCenter();

        p1 = Vector2(center.x + (p1.x - center.x) * scaleX,
            center.y + (p1.y - center.y) * scaleY);
        p2 = Vector2(center.x + (p2.x - center.x) * scaleX,
            center.y + (p2.y - center.y) * scaleY);
        p3 = Vector2(center.x + (p3.x - center.x) * scaleX,
            center.y + (p3.y - center.y) * scaleY);
        p4 = Vector2(center.x + (p4.x - center.x) * scaleX,
            center.y + (p4.y - center.y) * scaleY);
    }

    Shape::Circle::Circle(NVGcontext* vg, Vector2 position, float r, Color c) : vg(vg), position(position), radius(r), color(c) {}

    void Shape::Circle::Draw() {
        if (!vg || !visible) return;

        nvgBeginPath(vg);
        nvgCircle(vg, position.x, position.y, radius);
        nvgFillColor(vg, nvgRGBA(color.r, color.g, color.b, color.a));
        nvgClosePath(vg);
        nvgFill(vg);
    }

    void Shape::Circle::Show() {
        visible = true;
    }

    void Shape::Circle::Hide() {
        visible = false;
    }

    void Shape::Circle::SetColor(Color newColor) {
        color = newColor;
    }

    void Shape::Circle::MoveUp(float moveAmount) {
        position.y - moveAmount;
    }

    void Shape::Circle::MoveDown(float moveAmount) {
        position.y + moveAmount;
    }

    void Shape::Circle::MoveLeft(float moveAmount) {
        position.x - moveAmount;
    }

    void Shape::Circle::MoveRight(float moveAmount) {
        position.x + moveAmount;
    }

    void Shape::Circle::SetPosition(Vector2 newPosition) {
        position.x = newPosition.x;
        position.y = newPosition.y;
    }

    void Shape::Circle::SetRadius(int newRadius) {
        radius = newRadius;
    }

    bool Shape::Circle::IsMouseHovering() {
        Vector2 mousePosition = Input::GetMousePosition();

        float dx = mousePosition.x - position.x;
        float dy = mousePosition.y - position.y;
        float distanceSquared = dx * dx + dy * dy;

        return distanceSquared <= radius * radius;
    }

    void Shape::Circle::Scale(float scale) {
        float radius = GetRadius();
        radius *= scale;
    }
}