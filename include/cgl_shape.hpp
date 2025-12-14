#pragma once
#include <nanovg.h>
#include <vector>
#include "cgl_vector.hpp"
#include "cgl_color.hpp"
#include "cgl_position.hpp"

namespace cgl {
    class Shape {
    public:
        class Triangle {
        public:
            Triangle(NVGcontext* vg, Vector2 p1, Vector2 p2, Vector2 p3, Color color);
            void Draw();
            void SetPoints(Vector2 newP1, Vector2 newP2, Vector2 newP3);
            void Show();
            void Hide();
            void SetColor(Color newColor);
            Vector2 GetP1() const { return p1; }
            Vector2 GetP2() const { return p2; }
            Vector2 GetP3() const { return p3; }
            std::vector<Vector2> GetPoints() const {
                return { p1, p2, p3 };
            }
            void MoveUp(float moveAmount);
            void MoveDown(float moveAmount);
            void MoveLeft(float moveAmount);
            void MoveRight(float moveAmount);
            Vector2 GetCenter() const {
                return Vector2((p1.x + p2.x + p3.x) / 3.0f, (p1.y + p2.y + p3.y) / 3.0f);
            }
            void SetPosition(Vector2 newCenter);
            bool IsMouseHovering();
            void Scale(float scaleX, float scaleY);
        private:
            bool visible = true;
            NVGcontext* vg;

            Vector2 p1, p2, p3;
            Color color;
        };

        class Rectangle {
        public:
            Rectangle(NVGcontext* vg, Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, Color color);
            void Draw();
            void SetPoints(Vector2 newP1, Vector2 newP2, Vector2 newP3, Vector2 newP4);
            void Show();
            void Hide();
            void SetColor(Color newColor);
            Vector2 GetP1() const { return p1; }
            Vector2 GetP2() const { return p2; }
            Vector2 GetP3() const { return p3; }
            Vector2 GetP4() const { return p4; }
            std::vector<Vector2> GetPoints() const {
                return { p1, p2, p3, p4 };
            }
            void MoveUp(float moveAmount);
            void MoveDown(float moveAmount);
            void MoveLeft(float moveAmount);
            void MoveRight(float moveAmount);
            Vector2 GetCenter() const {
                return Vector2((p1.x + p2.x + p3.x + p4.x) / 4.0f, (p1.y + p2.y + p3.y + p4.y) / 4.0f);
            }
            void SetPosition(Vector2 newCenter);
            bool IsMouseHovering();
            void Scale(float scaleX, float scaleY);
        private:
            bool visible = true;
            NVGcontext* vg;

            Vector2 p1, p2, p3, p4;
            Color color;
        };
        static Shape::Triangle DefaultTriangle(NVGcontext* vg, Color color);
        static Shape::Rectangle DefaultSquare(NVGcontext* vg, Color color);

        class Circle {
        public:
            Circle(NVGcontext* vg, Vector2 position, float radius, Color color);
            void Draw();
            void Show();
            void Hide();
            void SetColor(Color newColor);
            void MoveUp(float moveAmount);
            void MoveDown(float moveAmount);
            void MoveLeft(float moveAmount);
            void MoveRight(float moveAmount);
            void SetPosition(Vector2 newCenter);
            void SetRadius(int newRadius);
            int GetRadius() const {
                return radius;
            }
            Vector2 GetPosition() const {
                return Vector2(position.x, position.y);
            }
            int GetCenterX() const {
                return position.x;
            }
            int GetCenterY() const {
                return position.y;
            }
            bool IsMouseHovering();
            void Scale(float scale);
        private:
            bool visible = true;
            NVGcontext* vg;
            Vector2 position;
            float radius;
            Color color;
        };
    };

}