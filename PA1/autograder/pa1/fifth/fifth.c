#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; j < argv[i][j]; j++)
        {
            switch (argv[i][j])
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    printf("%c", argv[i][j]);
                default:
                    continue;
            }
        }
    }
    return 0;
}