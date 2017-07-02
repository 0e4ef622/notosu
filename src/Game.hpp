#ifndef NOTOSU_GAME_HPP
#define NOTOSU_GAME_HPP

#include <SFML/Graphics.hpp>

class Scene;

class Game {
  public:
    void begin();
    void exit();
    void switchScene(Scene *targetScene);
  private:
    sf::RenderWindow *window;
    Scene *currentScene;
    void render();
};

#endif // NOTOSU_GAME_HPP
