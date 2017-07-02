#ifndef NOTOSU_SCENE_HPP
#define NOTOSU_SCENE_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "Game.hpp"

class Scene {
  public:
    std::vector<sf::Drawable*> objects;
    virtual void frame(Game *game, float deltaTimeSeconds) { }
    bool transitionFromDone = false;
  private:
    virtual void transitionIn() { }
    virtual void transitionOut() {
        transitionFromDone = true;
    }

    friend class Game;
};

#endif // NOTOSU_SCENE_HPP
