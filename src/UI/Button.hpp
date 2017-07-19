#ifndef NOTOSU_BUTTON_HPP
#define NOTOSU_BUTTON_HPP

#include <SFML/Graphics.hpp>

class Button {
  public:
    virtual void onClick() = 0;
    virtual bool contains(float x, float y) = 0;
};

class RectButton : public Button, public sf::FloatRect {
  public:
    RectButton() { };
    RectButton(const sf::FloatRect& rect) : sf::FloatRect(rect) { };

    bool contains(float x, float y) override final {
        return sf::FloatRect::contains(x, y);
    }
};

#endif // NOTOSU_BUTTON_HPP
