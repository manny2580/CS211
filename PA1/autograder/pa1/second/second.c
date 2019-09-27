#include <stdio.h>
#include <stdlib.h>

typedef struct LLNode
{
    int val;
    struct LLNode *next;
} LLNode;

LLNode *head;
int numNodes = 0;

LLNode* insert(LLNode *head, int val)
{
    ++numNodes;

    if (head == NULL) //empty linkedlist
    {
        head = (LLNode *) malloc(sizeof(LLNode));
        head -> val = val;
    }

    else
    {
        LLNode *temp = (LLNode *) malloc(sizeof(LLNode));
        temp -> val = val;
        LLNode *curr = head;
        LLNode *prev = NULL;

        while (curr != NULL)
        {
            if (curr -> val >= val)
            {
                if (curr == head)
                {
                    temp -> next = head;
                    head = temp;
                    break;
                }
                else if (prev -> val <= val)
                {
                    temp -> next = curr;
                    prev -> next = temp;
                    break;
                }
            }
            prev = curr;
            curr = curr -> next;
        }
        if (!curr && prev -> val <= val)
        {
            prev -> next = temp;
        }
    }
    return head;
}

LLNode* delete(LLNode *head, int val)
{
    if (head != NULL)
    {
        LLNode *curr =  head;
        LLNode *prev = NULL;
        while (curr != NULL)
        {
            if (curr -> val == val)
            {
                if (!curr -> next && !prev) //list has 1 item
                {
                    free(curr);
                    head = NULL;
                }
                else if (!curr -> next && prev) //end of list
                {
                    prev -> next = NULL;
                    free(curr);
                }
                else if (curr -> next && !prev) //at head, multiple items
                {
                    head = curr -> next;
                    free(curr);
                }
                else if (curr -> next && prev) //mid-list
                {
                    prev -> next = curr -> next;
                    free(curr);
                }
                --numNodes;
                break;
            }
            prev = curr;
            curr = curr -> next;
        }
    }
    return head;
}

void print(LLNode *head)
{
    printf("%d\n", numNodes);
    if (head != NULL)
    {
        LLNode *curr = head;
        LLNode *prev = NULL;
        while (curr != NULL)
        {
            if (!prev || (prev -> val != curr -> val))
            {
                printf("%d", curr -> val);
                if (curr -> next)
                {
                    printf("\t");
                }
            }
            prev = curr;
            curr = curr -> next;
        }
    }
}

int main(int argc, char** argv)
{
    head = NULL;

    FILE *file;
    file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("error");
        return 0;
    }

    char whatDo;
    int val;

    while (!feof(file))
    {
        fscanf(file, "%c\t%d\n", &whatDo, &val);

        if (whatDo == 'i')
        {
            head = insert(head, val);
        }
        else if (whatDo == 'd')
        {
            head = delete(head, val);
        }
    }

    fclose(file);
    print(head);

    return 0;
}