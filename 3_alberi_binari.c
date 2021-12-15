#include <stdio.h>
#include <stdlib.h>

struct BtreeNd
{
    int key;
    struct BtreeNd* parent;
    struct BtreeNd* left;
    struct BtreeNd* right;
};

typedef struct BtreeNd *bTree;

bTree NewNode(int key)
{
    bTree node = NULL;
    node = (bTree)malloc(sizeof(struct BtreeNd));
    node->left = NULL;
    node->right = NULL;
    node->key = key;
    return node;
}

bTree AddLeft(bTree n, int key)
{
    if (n == NULL)
        return NULL;

    return (n->left = NewNode(key));
}

bTree AddRight(bTree n, int key)
{
    if (n == NULL)
        return NULL;

    return (n->right = NewNode(key));
}

void TraverseTree(bTree root)
{
    if (root == NULL)
        return;
    while (root)
    {
        printf("%d ", root->key);
        if (root->left)
            TraverseTree(root->left);
        if (root->right)
            TraverseTree(root->right);
    }
}

// TODO: Return a pointer to the node with minimum key in tree bt
// btree MinInBtree(bTree bt)
// {
//     
// }
// TODO Return the nearest right ancestor to the node nd (or NULL if doesn't exist)
// btree RightAncestor(bTree nd)
// {
//     
// }
// TODO Return a pointer to the successor of node nd (or NULL if doesn't exist)
// btree Successor(bTree nd)
// {
//     
// }

int main()
{
    // TODO: Define btree here

    // TraverseTree(root);

    return 0;
}