#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_SYMB    100

int print_ch_num_seq(char *num_seq);
int sort_num_seq(char *num_seq);
    
int
main(int argc, char *argv[])
{
    char num_seq[MAX_SYMB];
    
    printf("Please, enter the sequence number \n");
    printf("Input format: non-empty string s that only\n"
            "contains digits 1,2 and 3 and characters +\n");

    fgets(num_seq, MAX_SYMB, stdin);
    if (num_seq == NULL)
    {
        fprintf(stderr, "Error: fgets return NULL");
        return -1;
    }

    printf("The input sequence number: \n");
    print_ch_num_seq(num_seq);
    sort_num_seq(num_seq);
    printf("The replaced sequence number: \n");
    print_ch_num_seq(num_seq);

    return 0;
}

int print_ch_num_seq(char *num_seq)
{
    size_t size_num_seq = strlen(num_seq);
    for (int i = 0; i <= size_num_seq; i++)
    {
        printf("%c", *(num_seq + i));
    }
    printf("\n");
    return 0;
}

int sort_num_seq(char num_seq[])
{
    size_t size_num_seq = strlen(num_seq);
    char tmp_ch;

    for (int i = 2; i < size_num_seq; i+=2)
    {
        for (int j = i; j > 0 && (num_seq[j - 2] >= num_seq[j]); j--)
        {
            tmp_ch = num_seq[j - 2];
            num_seq[j - 2] = num_seq[j];
            num_seq[j] = tmp_ch;
        }
    }
    return 0;
}
