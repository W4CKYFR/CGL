#pragma once
#include <string>
#include <GLFW/glfw3.h>
#include "cgl.hpp"
#include <nanovg.h>

namespace cgl {
    class Window {
    public:
        Window(int width, int height, const std::string& title);
        ~Window();

        bool ShouldClose() const;
        void PollEvents() const;
        void SwapBuffers() const;
        void clearColorBufferBit() const;
        void setColor(float Red, float Blue, float Green, float alpha) const;
        GLFWwindow* GetHandle() const;
        void Close() const;
        NVGcontext* GetVGContext() const;

    private:
        NVGcontext* vg = nullptr;
        GLFWwindow* handle = nullptr;
    };
}
