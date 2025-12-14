#pragma once

namespace cgl {
    struct Color {
        unsigned char r, g, b, a;

        static const Color White;
        static const Color Black;
        static const Color Red;
        static const Color Green;
        static const Color Blue;
        static const Color Magenta;
        static const Color Yellow;
    };
}