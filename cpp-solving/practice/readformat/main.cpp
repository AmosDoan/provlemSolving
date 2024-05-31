#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int N;
    char T[256];
    scanf("%d|%s", &N, T);

    string timeStamp(T);
    cout << N << "|" << T << endl;

    while(N--) {
        char timestamp[256], type[256], tid[256];
        int sid;
        scanf("%8s|%1s|%7s|%d", timestamp, type, tid, &sid);

        string timestampStr(timestamp);
        string typeStr(type);
        string tidStr(tid);

        cout << "timestamp" << timestampStr <<  endl;
        cout << timestampStr << "|" << typeStr << "|" << tidStr << endl;
    }
}
