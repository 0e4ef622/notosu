#include "Scene.hpp"

void Scene::transitionIn() {
    transitionFromDone = false;
}

void Scene::transitionOut() {
    transitionFromDone = true;
}

void Scene::draw(sf::RenderWindow &window) {
    for (sf::Drawable *object : objects) {
        window.draw(*object);
    }
}
