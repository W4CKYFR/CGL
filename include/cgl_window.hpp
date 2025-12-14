#pragma once
#include <string>
#include <GLFW/glfw3.h>
#include "cgl_color.hpp"
#include <nanovg.h>
#include <chrono>
#include "cgl_camera.hpp"

namespace cgl {
    class Window {
    public:
        Camera camera;

        Window(int width, int height, const std::string& title);
        ~Window();

        bool ShouldClose() const;
        void PollEvents() const;
        void SwapBuffers() const;
        void ClearColorBufferBit() const;
        void SetColor(const Color& c) const;
        GLFWwindow* GetHandle() const;
        void Close() const;
        NVGcontext* GetVGContext() const;
        double GetFPS() const;
        double GetDeltaTime() const;
        int GetWidth() const;
        int GetHeight() const;

    private:
        static std::chrono::high_resolution_clock::time_point lastTime;
        static double deltaTime;
        static double FPS;
        NVGcontext* vg = nullptr;
        GLFWwindow* handle = nullptr;
        int rWidth;
        int rHeight;
    };
}