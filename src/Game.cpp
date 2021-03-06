#include <iostream>
#include <SFML/Graphics.hpp>
#include "defs.h"
#include "Game.hpp"
#include "UI/Scene.hpp"
#include "UI/Button.hpp"
#include "scenes/SplashScene/SplashScene.hpp"

int WINDOW_WIDTH = 1024;
int WINDOW_HEIGHT = 600;

void Game::begin() {

    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "notosu", sf::Style::Titlebar | sf::Style::Close);
    currentScene = &splashScene;

    sf::Clock deltaClock;
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            switch (event.type) {

                case sf::Event::Closed:
                    window->close();
                    break;

                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        for (Button *button : currentScene->buttons) {
                            if (button->contains(event.mouseButton.x, event.mouseButton.y))
                                button->onClick();
                        }
                    }
                    break;

                default:
                    break;
            }
        }

        if (transitioningToScene != NULL && currentScene->transitionFromDone) {
            currentScene = transitioningToScene;
            currentScene->transitionFromDone = false;
            currentScene->transitionIn();
        }

        sf::Time deltaTime = deltaClock.restart();
        currentScene->frame(this, deltaTime.asSeconds());
        render();
    }
}

void Game::exit() {
    window->close();
}

void Game::render() {

    window->clear();

    currentScene->draw(*window);

    window->display();
}

void Game::switchScene(Scene &targetScene) {
    transitioningToScene = &targetScene;
    currentScene->transitionOut();
    //targetScene->transitionTo(); // something like this idk .-.
    //currentScene = targetScene;
}
