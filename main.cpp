// Copyright 2025 Mena Rezkalla
#include <string>
#include "PhotoMagic.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main(int argc, char* argv[]) {
     if (argc != 4) {
        return -1;
    }
    std::string input = argv[1];
    std::string output = argv[2];
    std::string seed = argv[3];
    sf::Image image;
    if (!image.loadFromFile(input))
        return -1;
    sf::Image backup = image;
    PhotoMagic::FibLFSR key("0000000000000000");
    if (seed.length() == 16)
        key = PhotoMagic::FibLFSR(seed);
    else
        key = PhotoMagic::FibLFSR::fromPassword(seed);

    PhotoMagic::transform(image, &key);
    if (!image.saveToFile(output))
        return -1;
    image = backup;
    sf::Texture texture1;
    texture1.loadFromImage(image);
    sf::Sprite sprite1;
    sprite1.setTexture(texture1);
    sf::Image outImage;
    if (!outImage.loadFromFile(output))
        return -1;

    sf::Texture texture2;
    texture2.loadFromImage(outImage);
    sf::Sprite sprite2;
    sprite2.setTexture(texture2);
    sf::Vector2u size1 = image.getSize();
    sf::RenderWindow window1(sf::VideoMode(size1.x, size1.y), input);
    sf::Vector2u size2 = outImage.getSize();
    sf::RenderWindow window2(sf::VideoMode(size2.x, size2.y), output);
    while (window1.isOpen() && window2.isOpen()) {
        sf::Event event;
        while (window1.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window1.close();
        }
        while (window2.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window2.close();
        }
        window1.clear();
        window1.draw(sprite1);
        window1.display();
        window2.clear();
        window2.draw(sprite2);
        window2.display();
    }
    return 0;
}
