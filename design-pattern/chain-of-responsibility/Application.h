//
// Created by Amos on 2020/03/06.
//

#ifndef CPPPRACTICE_APPLICATION_H
#define CPPPRACTICE_APPLICATION_H

#include "HelpHandler.h"

// Application Instance는 Widget이 아니므로 HelpHandler를 직접 상속
class Application : public HelpHandler {
public:
    Application(Topic t) : HelpHandler(nullptr, t) {}

    virtual void handleHelp();
};

#endif //CPPPRACTICE_APPLICATION_H
