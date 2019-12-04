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
int** genSols(int i, int n)
{

}

int main(int argc, char* argv[])
{
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        return 0;
    }

    char* op;
    int numVars;
    char* in1;
    char* in2;
    char* out;

    node* inputs = NULL;
    node* outputs = NULL;
    node* temps = NULL;

    //inputs
    fscanf(file, "%s %d ", &op, &numVars);
    node* inputs = NULL;
    for (int i = 0; i < numVars; i++)
    {
        char* nameVar;
        fscanf(file, "%s", &nameVar);
        add(inputs, 0, )
    }

    //FOR EACH COMBINATION OF INPUTS
    while (!feof(file))
    {
        fscanf(file, "%s ", &op);

        if (strcmp(op, "INPUTVAR") == 0)
        {
            fscanf(file, "%d ", &numVars);
            for (int i = 0; i < numVars; i++)
            {
                char* nameVar;
                fscanf(file, "%s", &nameVar);
                add(inputs, 0, )
            }
        }

        else if (strcmp(op, "OUTPUTVAR") == 0)
        {
            fscanf(file, "%d ", &numVars);
            for (int i = 0; i < numVars; i++)
            {
                char* nameVar;
                fscanf(file, "%s", &nameVar);
                add(inputs, 0, )
            }
        }

        else if(strcmp(op, "NOT") == 0)
        {

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

        //move to next line
    }

    //PRINT FORMAT CORRECTLY
    
    //use arrays for the inputs/outputs? because sizes are given
    //loop - for each line, set variables accordingly, then figure out the instruction - do that instruction
}
