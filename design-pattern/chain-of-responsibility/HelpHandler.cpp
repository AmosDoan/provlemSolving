//
// Created by Amos on 2020/03/06.
//

#include "HelpHandler.h"

HelpHandler::HelpHandler (HelpHandler *helpHandler, Topic topic) : _successor(helpHandler), _topic(topic) {}

bool HelpHandler::hasHelp() {
    return _topic != NO_HELP_TOPIC;
}

void HelpHandler::handleHelp() {
    if (_successor != nullptr) {
        _successor->handleHelp();
    }
}

