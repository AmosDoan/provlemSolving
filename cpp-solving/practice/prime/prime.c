#include <stdio.h>

#define N 500

int seive[N] = {0};
int prime[N] = {0};

int main(int argc, char **argv)
{
    int idx = 0, multiple = 2;
    seive[0] = -1; // 0은 소수가 아니기 때문에 -1로 미리 표시
    seive[1] = -1; // 1은 소수가 아니기 때문에 -1로 미리 표시

    for(int i = 0; i < N; i++)
    {
        if(seive[i] == -1)
            continue;

        prime[idx++] = i;
        //printf("[DEBUG] prime : %d idx : %d\n", prime[idx - 1], idx - 1);
        multiple = 2;
        for(int p = i * multiple; p < N; p = i * multiple)
        {
            //printf("[DEBUG] p : %d multiple : %d\n", p, multiple);
            seive[p] = -1;
            multiple++;
        }
    }

    for(int i = 0; i < idx; i++)
    {
        printf("%d\n", prime[i]);
    }
}
