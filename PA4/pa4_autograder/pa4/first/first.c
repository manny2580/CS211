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
 * Main method - read file + how to keep track of combinations of inputs
 * */



int main(int argc, char* argv[])
{
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        return 0;
    }
    
}
