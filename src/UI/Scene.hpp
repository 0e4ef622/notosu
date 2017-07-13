#ifndef NOTOSU_SCENE_HPP
#define NOTOSU_SCENE_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "Game.hpp"

class Scene {
  public:
    std::vector<sf::Drawable*> objects;
    bool transitionFromDone = false;
  protected:
    virtual void transitionIn();
    virtual void transitionOut();
    virtual void frame(Game *game, float deltaTimeSeconds) { }
    virtual void draw(sf::RenderWindow &window);

    friend class Game;
};

#endif // NOTOSU_SCENE_HPP
