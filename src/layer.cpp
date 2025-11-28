#include "cgl.hpp"

namespace cgl {

    void Layer::Draw() {
        for (auto& drawable : drawables) {
            std::visit([](auto dptr) { dptr->Draw(); }, drawable);
        }
    }

    void Layer::Show() {
        for (auto& drawable : drawables) {
            std::visit([](auto dptr) { dptr->Show(); }, drawable);
        }
    }

    void Layer::Hide() {
        for (auto& drawable : drawables) {
            std::visit([](auto dptr) { dptr->Hide(); }, drawable);
        }
    }
}