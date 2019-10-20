#include <stdio.h>
#include <stdlib.h>

unsigned int getParity(unsigned int i)
{
    int p = 0;
    while (i)
    {
        p = !p;
        i = i & (i-1);
    }
    return p;
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        return 0;
    }
    int a = atoi(argv[1]);
    int count = 0;
    int temp = a;

    while (a > 0)
    {
        if ( ((a >> 0) & 1) == 1)
        {
            a = a >> 1;
            if (((a >> 0) & 1) == 1)
            {
                a = a >> 1;
                count++;
            }
        }
        else
        { 
            a = a >> 1;
        }
    }

    if (getParity(temp))
    {
        printf("Odd-Parity\t");
    }
    else
    {
        printf("Even-Parity\t");
    }
    printf("%u\n", count);
    return 0;
}
