#include <SFML/Graphics.hpp>
#include "defs.h"
#include "ResourceManager.hpp"
#include "MainMenuScene.hpp"

MainMenuScene mainMenuScene;

MainMenuScene::MainMenuScene() {
    /*
     * sf::RectangleShape rect;
     * SomeButton someButton;
     * sf::RectangleShape fadeOverlay;
     */

    rect.setSize(sf::Vector2f(400, 50));
    rect.setOrigin(200, 25);
    rect.setPosition(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineThickness(3);
    rect.setOutlineColor(sf::Color::White);

    objects.push_back(&rect);

    someButton = SomeButton(rect.getGlobalBounds());
    buttons.push_back(&someButton);

    fadeOverlay.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
}

static float transparency;

void MainMenuScene::frame(Game *game, float deltaTimeSeconds) {
    if (transparency < 255.0f) {
        transparency += deltaTimeSeconds * 255.0f;
    }
}

void MainMenuScene::draw(sf::RenderWindow &window) {
    // draw everything first so that we can draw the fade overlay
    // on top of everything
    Scene::draw(window);

    // sf::RectangleShape fadeOverlay;

    if (transparency < 255.0f)
        fadeOverlay.setFillColor(sf::Color(0.0f, 0.0f, 0.0f, 255.0f - transparency));
    window.draw(fadeOverlay);
}

void MainMenuScene::transitionIn() {
    transparency = 0;
    transitionFromDone = false;
}
