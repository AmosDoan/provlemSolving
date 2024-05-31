//
// Created by Amos on 2020/03/06.
//

#include "Widget.h"

Widget::Widget(Widget *parent, Topic t) : HelpHandler(parent, t) {
    _parent = parent;
}
