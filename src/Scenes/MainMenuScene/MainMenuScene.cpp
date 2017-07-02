#include <SFML/Graphics.hpp>
#include "MainMenuScene.hpp"

MainMenuScene mainMenuScene;

static sf::RectangleShape *rect;
static sf::RectangleShape *fadeOverlay;

MainMenuScene::MainMenuScene() {

    rect = new sf::RectangleShape();

    rect->setSize(sf::Vector2f(400, 50));
    rect->setOrigin(200, 25);
    rect->setPosition(320, 240);
    rect->setFillColor(sf::Color::Transparent);
    rect->setOutlineThickness(3);
    rect->setOutlineColor(sf::Color::White);

    objects.push_back(rect);

    fadeOverlay = new sf::RectangleShape();

    fadeOverlay->setSize(sf::Vector2f(640, 480));
    fadeOverlay->setFillColor(sf::Color::Black);

    objects.push_back(fadeOverlay);
}

static float transparency;

void MainMenuScene::frame(Game *game, float deltaTimeSeconds) {
    if (transparency < 255.0f) {
        transparency += deltaTimeSeconds * 255.0f;
        fadeOverlay->setFillColor(sf::Color(0.0f, 0.0f, 0.0f, 255.0f - transparency));
    }
}

void MainMenuScene::transitionIn() {
    transparency = 0;
}
