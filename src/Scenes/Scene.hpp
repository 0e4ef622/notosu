#ifndef NOTOSU_SCENE_HPP
#define NOTOSU_SCENE_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "Game.hpp"

class Scene {
  public:
    std::vector<sf::Drawable*> objects;
    virtual void frame(Game *game, float deltaTimeSeconds) { }
  private:
    virtual void transitionTo() { }
    virtual void transitionFrom() { }

    friend void Game::switchScene(Scene *targetScene);
};

#endif // NOTOSU_SCENE_HPP
