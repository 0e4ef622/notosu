#ifndef NOTOSU_SCENE_HPP
#define NOTOSU_SCENE_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Button.hpp"

class Scene {
  protected:
    std::vector<sf::Drawable*> objects;
    std::vector<Button*> buttons;
    bool transitionFromDone = false;
    virtual void transitionIn();
    virtual void transitionOut();

    // things to be run every frame before rendering
    virtual void frame(Game *game, float deltaTimeSeconds) { }

    // do actual rendering
    virtual void draw(sf::RenderWindow &window);

    friend class Game;
};

#endif // NOTOSU_SCENE_HPP
