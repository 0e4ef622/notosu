#ifndef NOTOSU_MAINMENUSCENE_HPP
#define NOTOSU_MAINMENUSCENE_HPP

#include "Game.hpp"
#include "UI/Scene.hpp"

class MainMenuScene : public Scene {
  public:
    MainMenuScene();
    void frame(Game *game, float deltaTimeSeconds) override;
    void draw(sf::RenderWindow &window) override;
  protected:
    void transitionIn() override;
  private:
    sf::RectangleShape rect;
    sf::Text meems;

    sf::RectangleShape fadeOverlay;
};

extern MainMenuScene mainMenuScene;

#endif // NOTOSU_MAINMENUSCENE_HPP
