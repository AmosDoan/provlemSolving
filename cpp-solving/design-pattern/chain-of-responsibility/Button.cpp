//
// Created by Amos on 2020/03/06.
//

#include "Button.h"

Button::Button(Widget *d, Topic t) : Widget(d, t) {}

void Button::handleHelp() {
    if (hasHelp()) {
        // 보여줄 도움말이 있으면 이곳에 정의
    } else {
        HelpHandler::handleHelp();
    }
}
