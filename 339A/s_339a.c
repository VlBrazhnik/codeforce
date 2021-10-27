#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_SYMB    100

int print_ch_num_seq(char *num_seq);
int sort_num_seq(char *num_seq);
    
int
main(int argc, char *argv[])
{
    char *p_num_seq = "3+1+2+1";
    printf("the sequence number: \n");
    printf("The SeqN ptr: %s, sizeof(): %lu\n", p_num_seq, strlen(p_num_seq));

    print_ch_num_seq(p_num_seq);
    sort_num_seq(p_num_seq);
    print_ch_num_seq(p_num_seq);

    char *new_ch = "8";
    // memmove(p_num_seq, new_ch, sizeof(*new_ch));
    memset(p_num_seq, 0, sizeof(*p_num_seq));
    printf("The SeqN ptr: %s,", p_num_seq);

    return 0;
}

int print_ch_num_seq(char *num_seq)
{
    size_t size_num_seq = sizeof(num_seq) - 1;
    for (int i = 0; i <= size_num_seq; i+=2)
    {
        printf("%c", *(num_seq + i));
    }
    printf("\n");
    return 0;
}

int sort_num_seq(char *num_seq)
{
    size_t size_num_seq = sizeof(num_seq) - 1;
    char prev_ch;
    char next_ch;
    char tmp_ch;

    for (int i = 0; i <= size_num_seq; i+=2)
    {
        for (int j = i; j >= 0 && (prev_ch > next_ch); )
        {
            prev_ch = *(num_seq + j);
            tmp_ch = prev_ch;
            next_ch = *(num_seq + j + 2);
            prev_ch = next_ch;
            next_ch = tmp_ch;
        }
    }
    printf("num_seq: %s\n", num_seq);

    return 0;
}
