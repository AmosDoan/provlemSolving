#include <iostream>
#include <stack>

using namespace std;

stack<int> hanoi_stack;

void move(int from, int to)
{
    cout << "From " << from << " : To " << to << endl;
}    

void hanoi(int nr_sample, int from, int by, int to)
{
    while(1)
    {
        // 2개까지
        while(nr_sample > 1)
        {
            hanoi_stack.push(to);           // Argument Push
            hanoi_stack.push(by);
            hanoi_stack.push(from);
            hanoi_stack.push(nr_sample);
            nr_sample--;                    // Argument 변경
            hanoi_stack.push(to);           // To와 By의 교환
            to = by;
            by = hanoi_stack.top();
            hanoi_stack.pop();              // 매 단계마다 To와 By가 바뀜
        }

        move(from, to);                     // 한개를 옮김

        // Recursive 수행 루틴
        // n = 2부터 시작하여 옮김
        if(!hanoi_stack.empty())
        {
            nr_sample = hanoi_stack.top();
            hanoi_stack.pop();
            from = hanoi_stack.top();
            hanoi_stack.pop();
            by = hanoi_stack.top();
            hanoi_stack.pop();
            to = hanoi_stack.top();
            hanoi_stack.pop();

            move(from, to);

            // From, By 교체
            nr_sample--;
            hanoi_stack.push(from);
            from = by;
            by = hanoi_stack.top();
            hanoi_stack.pop();
        }
        else
            break;
    }
}

int main()
{
    int nr_sample;
    cin >> nr_sample;
    hanoi(nr_sample, 1, 2, 3);
    return 0;
}
