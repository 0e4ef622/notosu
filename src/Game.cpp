#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Scenes/Scene.hpp"
#include "Scenes/SplashScene/SplashScene.hpp"

void Game::begin() {

    window = new sf::RenderWindow(sf::VideoMode(640, 480), "notosu", sf::Style::Titlebar | sf::Style::Close);
    currentScene = &splashScene;

    sf::Clock deltaClock;
    while (window->isOpen()) {
        sf::Time deltaTime = deltaClock.restart();
        currentScene->frame(this, deltaTime.asSeconds());

        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }
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
    currentScene->transitionFrom();
    targetScene->transitionTo(); // something like this idk .-.
    currentScene = targetScene;
}
