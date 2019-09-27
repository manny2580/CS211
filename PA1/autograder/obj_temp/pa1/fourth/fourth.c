#include <stdio.h>
#include <stdlib.h>

int ** multiply(int ** mA, int ** mB, int ** res, int rows, int cols, int rows2)
{
    for (int i = 0; i < rows; i++)
    {
        res[i] = (int * ) calloc(cols, cols * sizeof(int));
        for (int j = 0; j < cols; j++)
        {
            for (int k = 0; k < rows2; k++)
            {
                res[i][j] += mA[i][k] * mB[k][j];
            }
        }
    }
    return res;
}

void freeArr(int ** m, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(m[i]);
    }
    free(m);
}

void print(int ** m, int r, int c)
{
    for(int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char ** argv)
{
    FILE *file;
    file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("error");
        return 0;
    }

    int i,j; //loop counters

    //read first matrix
    int x1;
    int y1;

    fscanf(file, "%d\t%d\n", &x1, &y1); //get the sizes

    int ** firstMat = (int **) malloc(x1*sizeof(int *)); //columns
    for (i = 0; i < x1; i++)
    {
        firstMat[i] = (int *) malloc(y1*sizeof(int)); //rows
        for (j = 0; j < y1; j++)
        {
            fscanf(file, "%d", &firstMat[i][j]);
        }
    }

    //read second matrix
    int x2;
    int y2;

    fscanf(file, "%d\t%d\n", &x2, &y2); //get the sizes

    int ** secMat = (int **) malloc(x2*sizeof(int *)); //columns
    for (i = 0; i < x2; i++)
    {
        secMat[i] = (int *) malloc(y2*sizeof(int)); //rows
        for (j = 0; j < y2; j++)
        {
            fscanf(file, "%d", &secMat[i][j]);
        }
    }

    fclose(file);

    //answer - y1 x x2

    int ** ans = (int **) calloc(x1, x1*sizeof(int *));

    if (y1 != x2)
    {
        printf("bad-matrices");
        return 0;
    }
    else
    {
        ans = multiply(firstMat, secMat, ans, x1, y2, x2);
    }

    print(ans, x1, y2);

    freeArr(firstMat, x1);
    freeArr(secMat, x2);
    freeArr(ans, x1);
    
    return 0;
}