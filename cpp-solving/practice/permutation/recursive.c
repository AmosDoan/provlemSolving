#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUGGING

void print_space(int step)
{
    int i = 0;
    for(i = 0; i < step; i++)
        printf("\t");
    printf("[DEBUG] step : %d ", step);
}

void perm(char *str, char *out, int *is_used, int len, int step)
{
    int i;

    // Base Case
    if(step == len)
    {
        out[step] = '\0';
        printf("%s\n", out);
        //printf("step : %d , len : %d\n", step, len);
        return;
    }

    // Recursive Case
    for(i = 0; i < len; i++)
    {
        // 이미 표시되었다면 넣지 않음 
        if(is_used[i])
            continue;
        out[step] = str[i];
        // 해당 문자로 같은 순열의 다른 문자조합을 만들기 위해서
        is_used[i] = 1;
        perm(str, out, is_used, len, step + 1);
        // 해당 문자로 같은 Step의 다른 문자조합을 만들기 위해서
        is_used[i] = 0;
    }
}

int main()
{
    int *is_used, len;
    char str[100], out[100]; 
    printf("Type the String : ");
    fgets(str, sizeof(str), stdin);

    len = strlen(str);
    
    is_used = (int *)malloc(sizeof(int) * (len - 1));
    memset(is_used, 0, sizeof(int) * (len - 1));

    perm(str, out, is_used, len - 1, 0);

    return 0;
}
