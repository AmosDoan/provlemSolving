#ifndef _COMBINATION_H_
#define _COMBINATION_H_

#include <string>

using namespace std;

class Combination 
{
    public :
        Combination(const string &in) : in_(in)
        {
        }
        ~Combination()
        {
        }

        void combination()
        {
            combination(0);
        }
    private :
        void combination(int start_idx);
        void recursivePrint(int step);
        const string &in_;
        string out_;
};

#endif
