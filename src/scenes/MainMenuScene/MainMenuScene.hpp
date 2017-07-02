#ifndef NOTOSU_MAINMENUSCENE_HPP
#define NOTOSU_MAINMENUSCENE_HPP

#include "Game.hpp"
#include "UI/Scene.hpp"

class MainMenuScene : public Scene {
  public:
    MainMenuScene();
    void frame(Game *game, float deltaTimeSeconds) override;
  private:
    void transitionIn() override;
};

extern MainMenuScene mainMenuScene;

#endif // NOTOSU_MAINMENUSCENE_HPP
