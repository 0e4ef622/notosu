#include <SFML/Graphics.hpp>
#include "MainMenuScene.hpp"

MainMenuScene mainMenuScene;

MainMenuScene::MainMenuScene() {
    sf::RectangleShape *rect = new sf::RectangleShape();
    rect->setSize(sf::Vector2f(400, 50));
    rect->setOrigin(200, 25);
    rect->setPosition(320, 240);
    rect->setFillColor(sf::Color::Transparent);
    rect->setOutlineThickness(3);
    rect->setOutlineColor(sf::Color::White);
    objects.push_back(rect);
}
