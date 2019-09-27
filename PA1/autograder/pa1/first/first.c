#include <stdio.h>
#include <stdlib.h>

/**
 * Write a program that will read an array from a file and sort the given array.
 * Input: file name
 * Output: array sorted w/ all even numbers in ascending order and all odd numbers in descending order
 */

/**
 * write sort method
 * in main method, make an even array and odd array + their sizes
 * sort each of those accordingly (even ascending, odd descending)
 * return them accordingly
 */

void sortUp(int a[], int size) //sort in ascending order
{
    int temp;
    for (int i = 0; i < size; ++i)
    {
        for (int j = i+1; j < size; ++j)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main(int argc, char** argv)
{
    FILE *file;
    file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("error");
        return 0;
    }
    
    int i = 0; int j = 0; int numOdds = 0; int numEvens = 0; int current; int size;

    int even[20];
    int odd[20];
    
    fscanf(file, "%d\n", &size);

    while(!feof(file))
    {
        if (feof(file))
        {
            break;
        }

        fscanf(file, "%d\t", &current);

        if(current % 2 == 0 || current == 0)
        {
            even[numEvens] = current;
            ++numEvens;
        }
        else
        {
            odd[numOdds] = current;
            ++numOdds;
        }
        i++;
    }

    fclose(file);

    sortUp(even, numEvens);
    sortUp(odd, numOdds);

    for (j = 0; j < numEvens; j++)
    {
        printf("%d\t", even[j]);
    }

    for(j = numOdds - 1; j >= 0; j--)
    {
        printf("%d\t", odd[j]);
    }
}