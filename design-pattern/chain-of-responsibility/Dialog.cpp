//
// Created by Amos on 2020/03/06.
//

#include "Dialog.h"

Dialog::Dialog(HelpHandler *h, Topic t) : Widget(0) {
    _handler = h;
    _topic = t;
}

void Dialog::handleHelp() {
    if (hasHelp()) {

    } else {
        HelpHandler::handleHelp();
    }
}


