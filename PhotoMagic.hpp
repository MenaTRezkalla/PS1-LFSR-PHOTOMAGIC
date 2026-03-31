// Copyright 2025 Mena Rezkalla
#pragma once

#include <SFML/Graphics.hpp>
#include "FibLFSR.hpp"

namespace PhotoMagic {
void transform(sf::Image& img, FibLFSR* lfsr);
}  // namespace PhotoMagic
