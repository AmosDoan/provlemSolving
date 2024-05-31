#include <stdio.h>
#include <string.h>

char buf[0x100];
char telephone[7];

char telephone_list[10][3] = 
{
    {'0', '0', '0'},    //0
    {'1', '1', '1'},    //1
    {'A', 'B', 'C'},
    {'D', 'E', 'F'},
    {'G', 'H', 'I'},
    {'J', 'K', 'L'},
    {'M', 'N', 'O'},
    {'P', 'R', 'S'},
    {'T', 'U', 'V'},
    {'W', 'X', 'Y'},
};

char getCharkey(int telephoneKey, int place)
{
    return telephone_list[telephoneKey][place];
}

void printWord(int idx, char *out)
{
    //printf("[Debug] idx : %d\n", idx);
    if(idx == 7)
    {
        printf("%s\n", out);
        return;
    }

    for(int i = 0; i < 3; i++)
    {
        int str_to_int = buf[idx] - '0';
        out[idx++] = getCharkey(str_to_int, i);
        printWord(idx--, out);
    }
}

int main(int argc, char **argv)
{
    printf("Input the telephone number : ");
    fgets(buf, sizeof(buf), stdin);

    buf[strlen(buf) - 1] = '\0';
    printWord(0, telephone);
}
