#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Scenes/SplashScene/SplashScene.hpp"
#include "Scenes/MainMenuScene/MainMenuScene.hpp"

SplashScene splashScene;

SplashScene::SplashScene() {

    sf::Font *font = new sf::Font();
    if (!font->loadFromFile("rsc/fonts/arial.ttf")) {
        //std::cerr << "rip someting hapen wit te font loading :(" << std::endl;
    }

    sf::Text *text = new sf::Text();
    text->setFont(*font);
    text->setString("notosu");
    text->setCharacterSize(100);
    text->setFillColor(sf::Color::White);

    sf::FloatRect boundingBox = text->getLocalBounds();
    sf::Vector2f center(boundingBox.left + boundingBox.width/2, boundingBox.top + boundingBox.height/2);

    text->setOrigin(center);
    text->setPosition(320, 240);

    objects.push_back(text);

}

static float elapsedTime = 0;
void SplashScene::frame(Game *game, float deltaTimeSeconds) {
    elapsedTime += deltaTimeSeconds;
    if (elapsedTime >= 3) game->switchScene(&mainMenuScene);
}
