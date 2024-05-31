#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "quick_sort.h"

#define NO_PRIME_NUMBER    -1
#define NR_MABANGJIN       100

typedef struct prime_info
{
    int *prime_list;
    int *used_list;
    int cnt_prime;
} prime_info_s;

int cnt_mabangjin = 0;
int mabangjin_list[NR_MABANGJIN][9];
int mabangjin_sum[NR_MABANGJIN];

int check_mirror(int *arr, int sum)
{
    int *matrix = (int *)malloc(sizeof(int) * 9);
    bool seq_flag = false, sum_flag = false;

    for(int i = 0; i < 9; i++)
        matrix[i] = arr[i];

    quick_sort(matrix, 0, 8);

    // Sum을 체크
    for(int i = 0; i < cnt_mabangjin; i++)
    {
        if(!memcmp(matrix, mabangjin_list[i], sizeof(int) * 9))
            seq_flag = true;
    }

    // 다시 Sum을 체크
    for(int i = 0; i < cnt_mabangjin; i++)
    {
        if(mabangjin_sum[i] == sum)
            sum_flag = true;
    }

    // 거울 혹은 중복 상이 아니므로 Array에 등록 
    if(!(seq_flag && sum_flag))
    {
        memcpy(mabangjin_list + cnt_mabangjin, matrix, sizeof(int) * 9);
        mabangjin_sum[cnt_mabangjin] = sum;
        cnt_mabangjin++;
        free(matrix);
        return 0;
    }

    free(matrix);
    return -1;
}

// Backtracking Set 줄이기
bool check_mabang(int *matrix, int position)
{
    static int sum;
    if(position < 4)
    {
        if(position == 3)
            sum = matrix[0] + matrix[1] + matrix[2];
        return true;
    }

    // Fallback
    switch(position)
    {
    case 8:
        if (matrix[1] + matrix[5] + matrix[8] != sum) 
            goto FAIL;
        if (matrix[7] + matrix[8] + matrix[4] != sum) 
            goto FAIL;
    case 7:
        if (matrix[0] + matrix[6] + matrix[7] != sum) 
            goto FAIL;
        if (matrix[2] + matrix[5] + matrix[7] != sum)
            goto FAIL;
    case 6:
        if (matrix[3] + matrix[5] + matrix[6] != sum) 
            goto FAIL;
    case 5:
        if (matrix[0] + matrix[5] + matrix[4] != sum) 
            goto FAIL;
    case 4:
        if (matrix[2] + matrix[3] + matrix[4] != sum) 
            goto FAIL;
    }

    return 1;
FAIL:
    return 0;
}

void backtracking(int position, prime_info_s *ptr_prime, 
                 int *ret)
{
    if(position >= 9)
    {
        int sum = ret[0] + ret[1] + ret[2];

        if(check_mirror(ret, sum) != -1)
        {
            printf("%d\t%d\t", cnt_mabangjin, sum);
            for(int i = 0; i < 9; i++)
                printf("%d\t", ret[i]);
            printf("\n");
        }
        return;
    }

    for(int i = 0; i < ptr_prime->cnt_prime; i++)
    {
        if(ptr_prime->used_list[i])
            continue;
        ret[position] = ptr_prime->prime_list[i];
        ptr_prime->used_list[i] = 1;

        if(check_mabang(ret, position))
            backtracking(position + 1, ptr_prime, ret);

        ptr_prime->used_list[i] = 0;
    }
}

void print_prime(prime_info_s *ptr_prime)
{
    for(int i = 0; i < ptr_prime->cnt_prime; i++)
        printf("%d\n", ptr_prime->prime_list[i]);
    printf("=================================\n");
    printf("Total Prime : %d\n", ptr_prime->cnt_prime);
}

void get_prime(int limit, prime_info_s *ptr_prime)
{
    int *prime_list = (int *)malloc(sizeof(int) * limit);
    int *filter_list = (int *)malloc(sizeof(int) * limit);
    int cnt_prime = 0, multiple_idx = 2;

    memset(prime_list, 0, sizeof(int) * limit);
    memset(filter_list, 0, sizeof(int) * limit);

    filter_list[0] = NO_PRIME_NUMBER;
    filter_list[1] = NO_PRIME_NUMBER;
    
    for(int i = 0; i < limit; i++)
    {
        if(filter_list[i] == NO_PRIME_NUMBER)
            continue;
        prime_list[cnt_prime++] = i;

        for(int j = multiple_idx * i; j < limit; j = multiple_idx * i)
        {
            filter_list[j] = NO_PRIME_NUMBER;
            multiple_idx++;
        }

        multiple_idx = 2;
    }

    int *list = (int *)malloc(sizeof(int) * cnt_prime);
    int *used = (int *)malloc(sizeof(int) * cnt_prime);
    memcpy(list, prime_list, sizeof(int) * cnt_prime);
    memset(used, 0, sizeof(int) * cnt_prime);

    ptr_prime->prime_list = list;
    ptr_prime->used_list = used;
    ptr_prime->cnt_prime = cnt_prime;

    free(prime_list);
    free(filter_list);
}

int main(int argc, char **argv)
{
    char buf[0x100];
    int limit, mabangjin[9] = {0};
    prime_info_s prime_info;
    printf("Input the Number : ");
    fgets(buf, sizeof(buf), stdin);

    limit = atoi(buf);

    // Stack Overflow를 고려하여 너무 큰 수는 받지 않는다.
    if(limit > 10000)
    {
        printf("Too Large Numbe!\n");
        return -1;
    }

    get_prime(limit, &prime_info);
    //print_prime(&prime_info);
    backtracking(0, &prime_info, mabangjin);

    free(prime_info.prime_list);
    free(prime_info.used_list);

    printf("Valid Mabangjin Count : %d\n", cnt_mabangjin);

    return 0;
}
