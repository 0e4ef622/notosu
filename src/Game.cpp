#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "UI/Scene.hpp"
#include "scenes/SplashScene/SplashScene.hpp"

void Game::begin() {

    window = new sf::RenderWindow(sf::VideoMode(640, 480), "notosu", sf::Style::Titlebar | sf::Style::Close);
    currentScene = &splashScene;

    sf::Clock deltaClock;
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
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

    for (sf::Drawable *object : currentScene->objects) {
        window->draw(*object);
    }
    window->display();
}

void Game::switchScene(Scene *targetScene) {
    transitioningToScene = targetScene;
    currentScene->transitionOut();
    //targetScene->transitionTo(); // something like this idk .-.
    //currentScene = targetScene;
}
