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
    int t = (x >> n) & 1;
    int y;
    if (t == v)
    {
        return y;
    }

    if (v == 0)
    {
        y = x ^ (1 << n);
    }

    if (v == 1)
    {
        y = (1 << n) | x; 
        return y;
    }
}

unsigned short comp(int x, int n)
{
    int t = (x >> n) & 1;
    if (t == 1)
    {

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
            set(x, n, s);
            printf("\n");
        }
        else if(compare(whatDo, "comp") == 0)
        {
            comp(x, n);
            printf("\n");
        }
        else if (compare(whatDo, "get") == 0)
        {
            get(x, n);
            printf("\n");
        }
    }

    fclose(file);
    return 0;
}
