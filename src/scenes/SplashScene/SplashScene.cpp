#include <iostream>
#include <SFML/Graphics.hpp>
#include "defs.h"
#include "Game.hpp"
#include "SplashScene.hpp"
#include "ResourceManager.hpp"
#include "scenes/MainMenuScene/MainMenuScene.hpp"

SplashScene splashScene;

SplashScene::SplashScene() {

    splashText.setFont(getResource<sf::Font>("rsc/fonts/arial.ttf"));
    splashText.setString("notosu");
    splashText.setCharacterSize(100);
    splashText.setFillColor(sf::Color::White);

    sf::FloatRect boundingBox = splashText.getLocalBounds();
    sf::Vector2f center(boundingBox.left + boundingBox.width/2, boundingBox.top + boundingBox.height/2);

    splashText.setOrigin(center);
    splashText.setPosition(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);

    objects.push_back(&splashText);
}

void SplashScene::frame(Game *game, float deltaTimeSeconds) {
    static float elapsedTime = 0;
    static float transparency = 0;
    if (elapsedTime >= 1) {
        if (transparency >= 255.0f) {
            game->switchScene(mainMenuScene);
        } else {
            transparency += deltaTimeSeconds * 255.0f;
            splashText.setFillColor(sf::Color(255.0f, 255.0f, 255.0f, 255.0f - transparency));
        }
    } else {
        elapsedTime += deltaTimeSeconds;
    }
}
