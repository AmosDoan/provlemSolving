//
// Created by Amos on 2020/03/06.
//

#include <iostream>
#include "HelpHandler.h"
#include "Application.h"
#include "Dialog.h"
#include "Button.h"

using namespace std;

const Topic PRINT_TOPIC = 1;
const Topic PAPER_ORIENTATION_TOPIC = 2;
const Topic APPLICATION_TOPIC = 3;

int main() {
    // 객체 생성 및 연결
    Application *application = new Application(APPLICATION_TOPIC);
    Dialog *dialog = new Dialog(application, PRINT_TOPIC);
    Button *button = new Button(dialog, PAPER_ORIENTATION_TOPIC);

    // 버튼 객체에서 도움말 탐색
    // 버튼은 이 요청을 바로 처리할 것임
    button->handleHelp();

    return 0;
}
