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
    int bit = (1 << n);
    if (v == 0)
    {
        return x & ~bit;
    }
    return (x|bit);
}

unsigned short comp(int x, int n)
{
    return x ^ (1 << n);
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
            x = set(x,n,v);
            printf("%d\n", x);
        }
        else if(compare(whatDo, "comp") == 0)
        {
            //x = comp(x,n);
            printf("%d\n", comp(x,n));
        }
        else if (compare(whatDo, "get") == 0)
        {
            //x = get(x,n);
            printf("%d\n", get(x,n));
        }
    }

    fclose(file);
    return 0;
}