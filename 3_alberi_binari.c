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

// TODO
// btree MinInBtree(bTree bt)
// {
//     
// }
// TODO
// btree RightAncestor(bTree bt)
// {
//     
// }
// TODO
// btree Successor(bTree bt)
// {
//     
// }

int main()
{
    // TODO: Define btree here

    // TraverseTree(root);

    return 0;
}