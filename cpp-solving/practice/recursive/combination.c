#include <stdio.h>
#include <string.h>

#define MAX_STRING 128
//#define DEBUG_PRACTIE

char input_str[MAX_STRING];
char buf[MAX_STRING];

void print_recursive(int idx)
{
    for(int i = 0; i < idx; i++)
        printf("\t");
}

void combination(int curbuf_idx, int inbuf_size, int start_idx)
{
    if(curbuf_idx >= inbuf_size)
    {
#ifdef DEBUG_PRACTIE
        if(inbuf_size == 3)
            printf("Inbuf Size - 3 : ");
#endif
        buf[curbuf_idx] = '\0';
        printf("%s\n", buf);
        return;
    }

    // 길이 3인 조합 abc를 출력하고, b부터 길이가 3인 조합을 만들고자할 때, 
    // 결국, Base Case로써, 본 루프에 들어가지 못하고 Recursive가 종료됨 
    // start_idx = 3이고, strlen(input_str) 역시 3이기 때문
    for(int i = start_idx; i < strlen(input_str); i++)
    {
#ifdef DEBUG_PRACTIE
        print_recursive(curbuf_idx);
        printf("[DEBUG] Character : %c Current Character Idx : %d  Loop Idx : %d Bufsize : %d\n", input_str[i], curbuf_idx, i, inbuf_size);
        print_recursive(curbuf_idx);
        printf("[DEBUG] Next Call Argument : %d, %d, %d\n", curbuf_idx + 1, inbuf_size, i + 1);
#endif

        buf[curbuf_idx] = input_str[i];
        combination(curbuf_idx + 1, inbuf_size, i + 1);
    }
}

int main(int argc, char **argv)
{
    printf("Input String : ");
    fgets(input_str, MAX_STRING, stdin);

    input_str[strlen(input_str) - 1] = '\0';

    for(int i = 0; i < strlen(input_str); i++)
    {
#ifdef DEBUG_PRACTIE
        printf("[DEBUG] i : %d\n", i);
#endif
        combination(0, i + 1, 0);
    }

    return 0;
}
