#pragma once
#include <nanovg.h>
#include <vector>
#include "cgl.hpp"

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
            Vector2 GetP1() const { return p1; }
            Vector2 GetP2() const { return p2; }
            Vector2 GetP3() const { return p3; }
            std::vector<Vector2> GetPos() const {
                return { p1, p2, p3 };
            }
            void MoveUp(float moveAmount);
            void MoveDown(float moveAmount);
            void MoveLeft(float moveAmount);
            void MoveRight(float moveAmount);
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
            Vector2 GetP1() const { return p1; }
            Vector2 GetP2() const { return p2; }
            Vector2 GetP3() const { return p3; }
            Vector2 GetP4() const { return p4; }
            std::vector<Vector2> GetPos() const {
                return { p1, p2, p3, p4 };
            }
            void MoveUp(float moveAmount);
            void MoveDown(float moveAmount);
            void MoveLeft(float moveAmount);
            void MoveRight(float moveAmount);

        private:
            bool visible = true;
            NVGcontext* vg;

            Vector2 p1, p2, p3, p4;
            Color color;
        };
        static Shape::Triangle DefaultTriangle(NVGcontext* vg, Color color);
        static Shape::Rectangle DefaultSquare(NVGcontext* vg, Color color);
    };

}