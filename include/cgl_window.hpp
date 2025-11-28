#pragma once
#include <string>
#include <GLFW/glfw3.h>
#include "cgl.hpp"
#include <nanovg.h>
#include <chrono>

namespace cgl {
    class Window {
    public:
        Window(int width, int height, const std::string& title);
        ~Window();

        bool ShouldClose() const;
        void PollEvents() const;
        void SwapBuffers() const;
        void ClearColorBufferBit() const;
        void SetColor(float Red, float Green, float Blue, float alpha) const;
        GLFWwindow* GetHandle() const;
        void Close() const;
        NVGcontext* GetVGContext() const;
        double GetFPS() const;
        double GetDeltaTime() const;

    private:
        static std::chrono::high_resolution_clock::time_point lastTime;
        static double deltaTime;
        static double FPS;
        NVGcontext* vg = nullptr;
        GLFWwindow* handle = nullptr;
    };
}