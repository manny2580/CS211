#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

//LINKED LIST

typedef struct node
{
    char* var;
    int val;
    node *next;
} node;

node* makeNode(char* v, int value, node* n)
{
    node* newNode = (node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        exit(0);
    }
    newNode->var = v;
    newNode->val = value;
    newNode->next = n;

    return newNode;
}

node* add(node* head; int value; char* varName)
{
    node* newNode = makeNode(varName, value, head);
    if (head == NULL) //empty LL
    {
        head = newNode;
    }
    else
    {
        node* ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
    return head;
}

node* search(node* head, char* var)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->var == var)
        {
            return ptr->val;
        }
        ptr = ptr->next;
    }
    return -1;
}

//OPERATIONS
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

//generate solution array
int[] genSols(int* n, int[]* a, int* i)
{
    if (i == n)
    {
        return a;
    }

    a[i] = 0;
    genSols(n, a, i+1);

    arr[i] = 1;
    genSols(n, a, i+1);
}

int main(int argc, char* argv[])
{
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        return 0;
    }

    char* op; //operation string
    int numVars = 0; //number of variables
    char* in1; //first arg
    char* in2; //second arg
    char* out; //output variable

    char** inputs = NULL; //array of INPUTVARS
    char** outputs = NULL; //array of OUTPUTVARS
    char** answers = NULL; //array of answers
    node* temps = NULL; //linkedlist of temp vars
    char* nameVar; //temp variable to store names

    //inputs
    fscanf(file, "%s %d ", &op, &numVars);
    int temp[numVars];
    int combos[] = genSols(numVars, combos, 0); //solution array

    for (int i = 0; i < numVars; i++)
    {
        fscanf(file, "%s", &nameVar);
        inputs[i] = nameVar;
    }

    //outputs
    fscanf(file, "%s %d ", &op, &numVars);
    for (int j = 0; j < numVars; j++)
    {
        fscanf(file, "%s", &nameVar);
        outputs[j] = nameVar;
    }

    //FOR EACH COMBINATION OF INPUTS
    //set input vars equal to the solution array's row
    //then
    for (int k = 0; k < pow(2, numVars); k++)
    {
        
        while (!feof(file))
        {
            fscanf(file, "%s ", &op);
            if(strcmp(op, "NOT") == 0)
            {
                fscanf(file, "%s %s %s \n",)
            }

            else if(strcmp(op, "AND") == 0)
            {

            }

            else if(strcmp(op, "OR") == 0)
            {

            }

            else if(strcmp(op, "NAND") == 0)
            {

            }

            else if(strcmp(op, "NOR") == 0)
            {

            }

            else if(strcmp(op, "XOR") == 0)
            {

            }

            //set respective position in solution array
            //move to next line
        }

    }

    //PRINT FORMAT CORRECTLY
    
    //use arrays for the inputs/outputs? because sizes are given
    //loop - for each line, set variables accordingly, then figure out the instruction - do that instruction
}
