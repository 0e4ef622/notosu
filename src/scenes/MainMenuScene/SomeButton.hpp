#ifndef NOTOSU_MAINMENUSCENE_SOMEBUTTON_HPP
#define NOTOSU_MAINMENUSCENE_SOMEBUTTON_HPP

#include "UI/Button.hpp"

class SomeButton : public Button {
  public:
    using Button::Button;
    void onClick() override;
};

#endif // NOTOSU_MAINMENUSCENE_SOMEBUTTON_HPP
