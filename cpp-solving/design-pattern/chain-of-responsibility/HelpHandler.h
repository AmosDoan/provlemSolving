//
// Created by Amos on 2020/03/06.
//

#ifndef CPPPRACTICE_HELPHANDLER_H
#define CPPPRACTICE_HELPHANDLER_H

typedef int Topic;
const Topic NO_HELP_TOPIC = -1;

class HelpHandler {
public:
    HelpHandler(HelpHandler* = 0, Topic = NO_HELP_TOPIC);
    virtual bool hasHelp();
    virtual void handleHelp();
private:
    HelpHandler * _successor = nullptr;
    Topic _topic;
};


#endif //CPPPRACTICE_HELPHANDLER_H
