// Copyright 2025 Mena Rezkalla
#include "PhotoMagic.hpp"

namespace PhotoMagic {
void transform(sf::Image& img, FibLFSR* lfsr) {
    sf::Color p;
    sf::Vector2u size = img.getSize();
    for (unsigned int x = 0; x < size.x; x++) {
        for (unsigned int y = 0; y < size.y; y++) {
            p = img.getPixel(x, y);
            p.r = p.r ^ lfsr->generate(10);
            p.g = p.g ^ lfsr->generate(10);
            p.b = p.b ^ lfsr->generate(10);
            img.setPixel(x, y, p);
        }
    }
}
}  // namespace PhotoMagic
