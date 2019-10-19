#include <stdio.h>
#include <stdlib.h>

int compare(char* s1, char* s2)
{
    while (*s1 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

unsigned short set(int x, int n, int v)
{
    int bit = (x >> n) & 1;
    unsigned short res;
    if (v == bit)
    {
        return x;
    }
    else
    {
        res = (x ^ (1 << n)); //toggle bit
    }
    
    return res;
}

unsigned short comp(int x, int n)
{
    int bit = (x >> n) & 1;
    int c;
    if (bit == 1)
    {
        c = 0;
    }
    else
    {
        c = 1;
    }

    unsigned short res;

    if (c == 0)
    {
        res = x ^ (1 << n);
    }
    else if (c == 1)
    {
        res = (1 << n) | x;
    }
    return res;
}

unsigned short get(int x, int n)
{
    return (x >> n) & 1;
}

int main(int argc, char* argv[])
{
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        return 0;
    }

    int x, n, v;
    char whatDo[10];

    fscanf(file, "%d", &x);

    while(!feof(file))
    {
        fscanf(file, "%s\t%d\t%d\n", whatDo, &n, &v);
        if(compare(whatDo, "set") == 0)
        {
            printf("%d\n", set(x, n, v));
        }
        else if(compare(whatDo, "comp") == 0)
        {
            printf("%d\n", comp(x,n));
        }
        else if (compare(whatDo, "get") == 0)
        {
            printf("%d\n", get(x,n));
        }
    }

    fclose(file);
    return 0;
}
