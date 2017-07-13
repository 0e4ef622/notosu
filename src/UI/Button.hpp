#ifndef NOTOSU_BUTTON_HPP
#define NOTOSU_BUTTON_HPP

#include <SFML/Graphics.hpp>

class Button : public sf::FloatRect {
  public:
    Button() : sf::FloatRect() { };
    Button(const sf::FloatRect& rect) : sf::FloatRect(rect) { };
    virtual void onClick() = 0;
};

#endif // NOTOSU_BUTTON_HPP
