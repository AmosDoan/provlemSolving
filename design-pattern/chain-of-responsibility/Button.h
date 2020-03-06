//
// Created by Amos on 2020/03/06.
//

#ifndef CPPPRACTICE_BUTTON_H
#define CPPPRACTICE_BUTTON_H


#include "Widget.h"

class Button : public Widget {
public:
    Button(Widget *d, Topic t = NO_HELP_TOPIC);

    // Button class에서 재정의해야하는 부모 class에 정의된 요청 처리 메소드
    virtual void handleHelp();

};


#endif //CPPPRACTICE_BUTTON_H
