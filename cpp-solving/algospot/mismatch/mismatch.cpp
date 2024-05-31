#include <iostream>
#include <stack>

using namespace std;

bool check_bracket(const char &a, const char &b)
{
    if(a == ')')
    {
        if(b == '(')
            return true;
        return false;
    }
    else if(a == '}')
    {
        if(b == '{')
            return true;
        return false;
    }
    else if(a == ']')
    {
        if(b == '[')
            return true;
        return false;
    }

    return false;
}

bool traverse_fomula(const string &ptr)
{
    stack<char> st;

    for(int i = 0; i < ptr.length(); i++)
    {
        if(ptr[i] == '(' || ptr[i] == '{' || ptr[i] == '[')
            st.push(ptr[i]);
        else
        {
            if(st.size() == 0)
                return false;
            char bracket = st.top();
            if(check_bracket(ptr[i], bracket))
            {
                st.pop();
                continue;
            }
            else
                return false;
            st.pop();
        }
    }

    if(st.size() != 0)
        return false;
    return true;
}


int main()
{
    int sample_case;
    cin >> sample_case;

    for(int i = 0; i < sample_case; ++i)
    {
        string temp;
        cin >> temp;
        if(traverse_fomula(temp))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}

