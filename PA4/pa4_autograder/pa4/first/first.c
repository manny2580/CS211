#include <stdio.h>

/*
 * Input: a file listing a circuit description + directives on each line
 * 
 * Go through the file with every possible combination of inputs
 * 
 * Output: truth table for the circuit description
 * 
 * Todo:
 * Code each of the operations (NOT, AND, OR, NAND, NOR, XOR)
 * Main method - read file + how to keep track of combinations of inputs - greycode?
 * */

int not(int* in)
{
    if (in == 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int and(int* in1, int* in2)
{
    if (in1 == 1 && in2 == 1)
    {
        return 1;
    }
    return 0;
}

int or(int* in1, int* in2)
{
    if (in1 == 1 || in2 == 1)
    {
        return 1;
    }
    return 0;
}

int nand(int* in1, int* in2)
{
    return not(*and(in1, in2));
}

int nor(int* in1, int* in2)
{
    return not(*or(in1, in2));
}

int xor(int* in1, int* in2)
{
    if (in1 == in2)
    {
        return 0;
    }
    return 1;
}

int main(int argc, char* argv[])
{
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        return 0;
    }

    //use arrays for the inputs/outputs? because sizes are given
    //loop - for each line, set variables accordingly, then figure out the instruction - do that instruction
}
