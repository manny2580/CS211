#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct inst
{
    char op[8];
    int n;
    int s;
    int *ins;
    int *outs;
    int *sels;
} inst;

int addInputs(int *arr, int count)
{
    for (int i = count + 1; i >= 2; i--)
    {
        arr[i] = !arr[i];
        if (arr[i] == 1)
        {
            return 1;
        }
    }
    return 0;
}

//operations

void not(int *vals, int i, int o)
{
    vals[o] = !vals[i];
}

void and(int *vals, int i1, int i2, int o)
{
    vals[o] = vals[i1] && vals[i2];
}

void or(int *vals, int i1, int i2, int o)
{
    vals[o] = vals[i1] || vals[i2];
}

void nand(int *vals, int i1, int i2, int o)
{
    vals[o] = !(vals[i1] && vals[i2]);
}

void nor(int *vals, int i1, int i2, int o)
{
    vals[o] = !(vals[i1] || vals[i2]);
}

void xor(int *vals, int i1, int i2, int o)
{
    vals[o] = vals[i1] ^ vals[i2];
}

void printOut(int s, char **a)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s\n", a[i]);
    }
}

int indexOf(int s, char **a, char *t)
{
    for (int i = 0; i < s; i++)
    {
        if (strcmp(arr[i], t) == 0)
        {
            return i;
        }
    }
    return -1;
}

void reset(int s, int *a)
{
    for (int i = 0; i < s; i++)
    {
        a[i] = 0;
    }
    a[1] = 1;
}

int main(int argc, char** argv)
{
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        return 0;
    }

    //initializing everything
    int count = 0;
    inst steps = NULL;
    int size = 2;
    int ins = 0;
    int outs = 0;
    int ts = 0;
    char inst[8];
    char **names;
    int *vals = malloc(size * sizeof(int));

    //input
    fscanf(file, " %s", inst);
    fscanf(file, "%d", &ins);

    size += ins;
    names = malloc(size * sizeof(char *));
    names[0] = malloc(2 * sizeof(char));
    names[0] = "0\0";
    names[1] = malloc(2 * sizeof(char));
    names[1] = "1\0";

    int i;
    for (i = 0; i < ins; i++)
    {
        names[i+2] = malloc(8 * sizeof(char));

    }
}