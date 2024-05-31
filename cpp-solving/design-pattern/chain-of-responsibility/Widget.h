//
// Created by Amos on 2020/03/06.
//

#ifndef CPPPRACTICE_WIDGET_H
#define CPPPRACTICE_WIDGET_H


#include "HelpHandler.h"

class Widget : public HelpHandler {
protected:
    Widget(Widget *parent, Topic t = NO_HELP_TOPIC);
private:
    Widget *_parent;
};


#endif //CPPPRACTICE_WIDGET_H
