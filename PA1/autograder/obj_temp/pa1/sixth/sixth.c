#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode
{
    int val;
    struct BSTNode * left;
    struct BSTNode * right;
} BSTNode;

BSTNode * newNode(int val)
{
    BSTNode * n = (BSTNode * ) malloc(sizeof(BSTNode));
    n -> val = val;
    n -> left = NULL;
    n -> right = NULL;
    return n;
}

BSTNode * insert(BSTNode *root, int val)
{
    if (!root) //empty tree
    {
        return newNode(val);
    }
    if (val == root -> val) //in tree
    {
        return root;
    }

    //R E C U R S I O N
    if (val < root -> val)
    {
        root -> left = insert(root -> left, val);
    }
    else if (val > root -> val)
    {
        root -> right = insert(root -> right, val);
    }

    return root;
}

void print(BSTNode * root)
{
    if (root)
    {
        print(root -> left);
        printf("%d\t", root -> val);
        print(root -> right);
    }
}

void freeBST(BSTNode * root)
{
    if (root)
    {
        freeBST(root -> left);
        freeBST(root -> right);
        free(root);
    }
}

int main (int argc, char ** argv)
{
    FILE *file;
    file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("error");
        return 0;
    }

    int insertVal;
    BSTNode * BSTroot = NULL;

    while (!feof(file))
    {
        fscanf(file, "i\t%d\n", &insertVal);
        BSTroot = insert(BSTroot, insertVal);
    }

    fclose(file);

    print(BSTroot);
    freeBST(BSTroot);

    return 0;
}