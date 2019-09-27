#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

typedef struct LLNode
{
    int val;
    struct LLNode *next;
} LLNode;

int collides = 0;
int searches = 0;
LLNode* freeNodes[MAX_SIZE + 1];
int inserts = 0;

void insert(int key, LLNode* map[])
{
    int hash = key % MAX_SIZE;
    if (hash < 0) //this is possible bc C
    {
        hash += 10000;
    }
    if (hash > MAX_SIZE)
    {
        return;
    }

    //new node
    LLNode* hashNode = (LLNode * ) malloc(sizeof(LLNode));
    hashNode -> val = key;

    if (map[hash] != NULL) //collision!
    {
        ++collides;
        LLNode* head = map[hash];

        while(head)
        {
            if (head -> val == key)
            {
                free(hashNode);
                return;
            }
            if (!(head -> next))
            {
                head -> next = hashNode;
                freeNodes[inserts] = hashNode;
                return;
            }
            head = head -> next;
        }
    }
    else
    {
        hashNode -> next = NULL;
        map[hash] = hashNode;
        freeNodes[inserts] = hashNode;
    }
}

void search(int key, LLNode* map[])
{
    int hash = key % MAX_SIZE;

    if (hash < 0)
    {
        hash += 10000;
    }
    if (hash > MAX_SIZE)
    {
        return;
    }

    if (map[hash])
    {
        LLNode* head = map[hash];
        while (head != NULL)
        {
            if (head -> val == key)
            {
                ++searches;
            }
            head = head -> next;
        }
    }
}

void freeSpaces(int inserts, LLNode * freeNodes[])
{
    for (int i = 0; i < inserts; i++)
    {
        if (freeNodes[i] != NULL)
        {
            free(freeNodes[i]);
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

    char whatDo;
    int key;
    LLNode* map[MAX_SIZE + 1]; //including 10000

    for (int i = 0; i < MAX_SIZE; i++) //array clear time
    {
        map[i] = NULL;
    }

    while (!feof(file))
    {
        fscanf(file, "%c\t%d\n", &whatDo, &key);
        if (whatDo == 'i')
        {
            insert(key, map);
            ++inserts;
        }
        else if(whatDo == 's')
        {
            search(key, map);
        }
    }

    fclose(file);

    printf("%d\n", collides);
    printf("%d", searches);
    freeSpaces(inserts, freeNodes);

    return 0;
}