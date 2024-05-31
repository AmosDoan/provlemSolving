//
// Created by Amos on 2020/03/06.
//

#ifndef CPPPRACTICE_DIALOG_H
#define CPPPRACTICE_DIALOG_H


#include "Widget.h"

class Dialog : public Widget {
public:
    Dialog(HelpHandler* h, Topic t = NO_HELP_TOPIC);
    virtual void handleHelp();
    // Dialog class가 재정의한 Widget 연산 여기에
private:
    HelpHandler *_handler;
    Topic _topic;
};


#endif //CPPPRACTICE_DIALOG_H
