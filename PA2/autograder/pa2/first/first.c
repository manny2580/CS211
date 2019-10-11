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
    if (bit == v)
    {
        return x;
    }
    if (bit == 0)
    {
        x = x ^ (1 << n);
        return x;
    }
    if (bit == 1)
    {
        x = (1 << n) | x;
        return x;
    }
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

    if (c == 0)
    {
        x = x ^ (1 >> n);
        return x;
    }
    if (c == 1)
    {
        x = (1 << n) | x;
        return x;
    }
}

unsigned short get(int x, int n)
{
    int ans = (x >> n) & 1;
    return ans;
}

int main(int argc, char* argv[])
{
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        return 0;
    }

    int x, n, s;
    char whatDo[10];

    fscanf(file, "%d", &x);

    while(!feof(file))
    {
        fscanf(file, "%s\t%d\t%d\n", whatDo, &n, &s);
        if(compare(whatDo, "set") == 0)
        {
            printf("%d\n", set(x, n, s));
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
