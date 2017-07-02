#ifndef NOTOSU_SPLASHSCENE_HPP
#define NOTOSU_SPLASHSCENE_HPP

#include "Game.hpp"
#include "UI/Scene.hpp"

class SplashScene : public Scene {
  public:
    SplashScene();
    void frame(Game *game, float deltaTimeSeconds) override;
};

extern SplashScene splashScene;

#endif // NOTOSU_SPLASHSCENE_HPP
