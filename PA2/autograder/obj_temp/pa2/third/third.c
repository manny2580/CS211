#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        return 0;
    }
    unsigned short x = (unsigned short) atoi(argv[1]);
    
    int end = 15;
    int st = 0;

    for (st = 0; st < end; st++)
    {
        if(((x >> end) & 1) != ((x >> st) & 1))
        {
            printf("Not-Palindrome");
            return 0;
        }
        end--;
    }
    printf("Is-Palindrome");
}