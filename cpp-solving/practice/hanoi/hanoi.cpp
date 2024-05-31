#include <iostream>

using namespace std;

void move(int from, int to)
{
    cout << "From " << from << " : To " << to << endl;
}    

// From : 원래 있던 자리
// Tmp : 거쳐갈 자리
// To : 도착할 자리
void hanoi(int n, int from, int by, int to)
{
    if(n == 1)
        move(from, to);                 // 1번 원반을 옮기는 경우
    else
    {
        hanoi(n - 1, from, to, by);    // n - 1개를 일단 임시 거처로 옮김..
        move(from, to);                 // 나머지 하나를 목적지로 옮김
        hanoi(n - 1, by, from, to);    // n -1개를 다시 목적지로
    }
}

int main()
{
    int nr_sample;
    cin >> nr_sample;
    hanoi(nr_sample, 1, 2, 3);
    return 0;
}
