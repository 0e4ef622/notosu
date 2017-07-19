#ifndef NOTOSU_MAINMENUSCENE_HPP
#define NOTOSU_MAINMENUSCENE_HPP

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "UI/Scene.hpp"
#include "UI/Button.hpp"

class MainMenuScene final : public Scene {
  public:
    MainMenuScene();
    void frame(Game *game, float deltaTimeSeconds) override;
    void draw(sf::RenderWindow &window) override;
  protected:
    void transitionIn() override;
  private:
    sf::RectangleShape rect;

    class SomeButton final : public RectButton {
      public:
        using RectButton::RectButton;
        void onClick() override;
    } someButton;

    sf::RectangleShape fadeOverlay;
};

extern MainMenuScene mainMenuScene;

#endif // NOTOSU_MAINMENUSCENE_HPP
