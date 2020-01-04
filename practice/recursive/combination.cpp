#include <iostream>
#include <string>

#include "combination.h"

//#define DEBUG_PRACTIE

using namespace std;

void Combination::recursivePrint(int step)
{
    for(int i = 0; i < step; i++)
        cout << "\t";
}

void Combination::combination(int start_idx)
{
    for(int i = start_idx; i < in_.length(); i++)
    {
#ifdef DEBUG_PRACTIE
        recursivePrint(start_idx);
        cout << "[DEBUG] : in_.length() : " << in_.length() << endl;
        recursivePrint(start_idx);
        cout << "[DEBUG] : start_idx : " << start_idx << endl;
#endif
        out_ += in_.at(i);
#ifdef DEBUG_PRACTIE
        recursivePrint(start_idx);
#endif
        cout << out_ << endl;
        if(start_idx < in_.length())
            combination(i + 1);
        out_.resize(out_.length() - 1);
    }
} 
int main(int argc, char **argv)
{
    string input_str;
    cout << "Input String : ";
    cin >> input_str;

//#ifdef DEBUG_PRACTIE
//    cout << "[DEBUG] : input_str.length : " << input_str.length() 
//        << endl;
//#endif
    Combination comb(input_str);
    comb.combination();

    return 0;
}
