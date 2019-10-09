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

}

unsigned short comp(int x, int n)
{

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
            set(x, n, s)
        }
        else if(compare(whatDo, "comp") == 0)
        {
            comp(x, n);
        }
        else if (compare(whatDo, "get") == 0)
        {
            get(x, n);
        }
    }

    fclose(file);
    return 0;
}
