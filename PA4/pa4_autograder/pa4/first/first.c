#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct inst
{
    char op[100];
    int n;
    int s;
    int *ins;
    int *outs;
    int *sels;
}inst;

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
    for (int i = 0; i < s; i++)
    {
        printf("%s\n", a[i]);
    }
}

int indexOf(int s, char **a, char *t)
{
    for (int i = 0; i < s; i++)
    {
        if (strcmp(a[i], t) == 0)
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
    //printf("I Run\n");
    FILE *file = fopen(argv[1], "r");
    if (argc < 2)
    {
        return 0;
    }
    if (file == NULL)
    {
        return 0;
    }

    //initializing everything
    int count = 0;
    inst* steps = NULL;
    int size = 2;
    int ins = 0;
    int outs = 0;
    int ts = 0;
    char direc[100];
    char **names;
    int *vals = malloc(size * sizeof(int));

    //input
    fscanf(file, " %s", direc);
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
        names[i+2] = malloc(100 * sizeof(char));
        fscanf(file, "%*[: ]%16s", names[i + 2]);
    }

    //output
    fscanf(file, " %s", direc);
    fscanf(file, "%d", &outs);
    size += outs;
    names = realloc(names, size * sizeof(char *));
    for (i = 0; i < outs; i++)
    {
        names[i + ins + 2] = malloc(100*sizeof(char));
        fscanf(file, "%*[: ]%16s", names[i + ins+ 2]);
    }

    //steps
    inst step;
    while (!feof(file))
    {
        int numIns = 2;
        int numOuts = 1;
        //inst step;
        int sCount = fscanf(file, " %s", direc);
        if (sCount != 1)
        {
            break;
        }
        count++;
        step.n = 0;
        step.s = 0;
        strcpy(step.op, direc);

        if (strcmp(direc, "NOT") == 0) 
        {
            numIns = 1;
        }

        step.ins = malloc(numIns * sizeof(int));
        step.outs = malloc(numOuts * sizeof(int));
        step.sels = malloc(step.s * sizeof(int));

        char v[100];
        for (i = 0; i < numIns; i++) 
        {
            fscanf(file, "%*[: ]%16s", v);
            step.ins[i] = indexOf(size, names, v);
        }
        for (i = 0; i < step.s; i++) 
        {
            fscanf(file, "%*[: ]%16s", v);
            step.sels[i] = indexOf(size, names, v);
        }
        for (i = 0; i < numOuts; i++) 
        {
            fscanf(file, "%*[: ]%16s", v);
            int idx = indexOf(size, names, v);
            if (idx == -1) {
                size++;
                ts++;
                names = realloc(names, size * sizeof(char *));
                names[size - 1] = malloc(17 * sizeof(char));
                strcpy(names[size - 1], v);
                step.outs[i] = size - 1;
            }
            else 
            {
                step.outs[i] = idx;
            }
        }

        //add step to list
        if (steps == NULL) {
            steps = malloc(sizeof(inst));
        } else {
            steps = realloc(steps, count * sizeof(inst));
        }
        steps[count - 1] = step;
    }

    //initialize vals array
    vals = malloc(size * sizeof(int));
    reset(size, vals);

    while (1 < 2)
    {
        //print inputs
        for (i = 0; i < ins; i++)
        {
            printf("%d ", vals[i + 2]);
        }

        //calculations
        for (i = 0; i < count; i++)
        {
            inst step = steps[i];
            if (strcmp(step.op, "NOT") == 0) 
            {
                not(vals, step.ins[0], step.outs[0]);
            }
            if (strcmp(step.op, "AND") == 0) 
            {
                and(vals, step.ins[0], step.ins[1], step.outs[0]);
            }
            if (strcmp(step.op, "OR") == 0) 
            {
                or(vals, step.ins[0], step.ins[1], step.outs[0]);
            }
            if (strcmp(step.op, "NAND") == 0) 
            {
                nand(vals, step.ins[0], step.ins[1], step.outs[0]);
            }
            if (strcmp(step.op, "NOR") == 0) 
            {
                nor(vals, step.ins[0], step.ins[1], step.outs[0]);
            }
            if (strcmp(step.op, "XOR") == 0) 
            {
                xor(vals, step.ins[0], step.ins[1], step.outs[0]);
            }
        }

        //print outputs
        for (i = 0; i < outs; i++) 
        {
            printf("%d ", vals[ins + i + 2]);
        }
        printf("\n");

        if (!addInputs(vals, ins)) 
        {
            break;
        }
    }

    free(vals);
    free(names);
    //free(step.op);
    free(step.ins);
    free(step.outs);
    free(step.sels);
    fclose(file);

    return 0;
}