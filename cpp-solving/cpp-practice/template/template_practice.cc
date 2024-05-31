#include <iostream>

template<typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}

int main()
{
    int char1_HP {300};
    int char2_HP {400};
    int max_HP = max(char1_HP, char2_HP);

    std::cout << "HP MAX : " << max_HP << std::endl;

    float char1_EXP {250.0f};
    float char2_EXP {250.57f};
    float max_EXP = max(char1_EXP, char2_EXP);

    std::cout << "EXP MAX : " << max_EXP << std::endl;

    return 0;
}
