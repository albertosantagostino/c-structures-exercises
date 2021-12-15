#include <stdio.h>
#include <stdlib.h>

struct kTreeVertex
{
    int key;
    struct kTreeVertex *child;
    struct kTreeVertex *sibling;
};

typedef struct kTreeVertex *kTree;

kTree NewNode(int key)
{
    kTree node = NULL;
    node = (kTree)malloc(sizeof(struct kTreeVertex));
    node->sibling = NULL;
    node->child = NULL;
    node->key = key;
    return node;
}

kTree AddSibling(kTree n, int key)
{
    if (n == NULL)
        return NULL;

    while (n->sibling)
        n = n->sibling;

    return (n->sibling = NewNode(key));
}

kTree AddChild(kTree n, int key)
{
    if (n == NULL)
        return NULL;

    // Check if child list not empty
    if (n->child)
        return AddSibling(n->child, key);
    else
        return (n->child = NewNode(key));
}

void TraverseTree(kTree root)
{
    if (root == NULL)
        return;
    while (root)
    {
        printf("%d ", root->key);
        if (root->child)
            TraverseTree(root->child);
        root = root->sibling;
    }
}

// TODO
// int CountInt(kTree t)
// {
//     
// }

int main()
{
    kTree root = NewNode(12);
    kTree a1 = AddChild(root, 22);
    kTree a2 = AddChild(a1, 1);
    kTree b1 = AddChild(root, 2);
    kTree c1 = AddChild(root, 32);
    kTree c2 = AddChild(c1, 3);
    kTree c3 = AddChild(c1, 4);

    TraverseTree(root);

    return 0;
}