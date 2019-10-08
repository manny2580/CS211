#include <stdio.h>
#include <stdlib.h>

int set(int x, int n, int v)
{

}

int comp(int x, int n)
{

}

int get (int x, int n)
{

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
    }
}
