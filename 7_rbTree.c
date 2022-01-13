#include <stdio.h>
#include <stdlib.h>

#define BLACK 0
#define RED 1

struct RBtree
{
  int key;
  int color;
  struct RBtree *parent;
  struct RBtree *left;
  struct RBtree *right;
};

typedef struct RBtree *rbTree;

rbTree NewNode(int key)
{
  rbTree node = NULL;
  node = (rbTree)malloc(sizeof(struct RBtree));
  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
  node->key = key;
  node->color = RED;
  return node;
}

rbTree root = NULL;

rbTree BSTInsert(rbTree root, rbTree pt)
{
  if (root == NULL)
    return pt;

  if (pt->key < root->key)
  {
    root->left = BSTInsert(root->left, pt);
    root->left->parent = root;
  }
  else if (pt->key > root->key)
  {
    root->right = BSTInsert(root->right, pt);
    root->right->parent = root;
  }
  return root;
}

void RightRotate(rbTree n)
{
  rbTree nleft = n->left;
  n->left = nleft->right;

  if (nleft->right)
  {
    nleft->right->parent = n;
  }
  nleft->parent = n->parent;

  if (!n->parent)
  {
    root = nleft;
  }
  else if (n == n->parent->right)
  {
    n->parent->right = nleft;
  }
  else
  {
    n->parent->left = nleft;
  }
  nleft->right = n;
  n->parent = nleft;
}

void LeftRotate(rbTree n)
{
  rbTree nright = n->right;
  n->right = nright->left;

  if (nright->left)
  {
    nright->left->parent = n;
  }
  nright->parent = n->parent;

  if (!n->parent)
  {
    root = nright;
  }
  else if (n == n->parent->left)
  {
    n->parent->left = nright;
  }
  else
  {
    n->parent->right = nright;
  }
  nright->left = n;
  n->parent = nright;
}

void FixTree(rbTree root, rbTree pt)
{
  rbTree parent_pt = NULL;
  rbTree grand_parent_pt = NULL;

  while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED))
  {
    parent_pt = pt->parent;
    grand_parent_pt = pt->parent->parent;

    // CASO A: Parent of pt is left child of grandparent of pt
    if (parent_pt == grand_parent_pt->left)
    {
      rbTree uncle_pt = grand_parent_pt->right;

      // CASO 1: Uncle of pt is also red. Recoloring is required
      if (uncle_pt != NULL && uncle_pt->color == RED)
      {
        grand_parent_pt->color = RED;
        parent_pt->color = BLACK;
        uncle_pt->color = BLACK;
        pt = grand_parent_pt;
      }
      else
      {
        // CASO 2: pt is right child of its parent. Left-rotation required
        if (pt == parent_pt->right)
        {
          LeftRotate(parent_pt);
          pt = parent_pt;
          parent_pt = pt->parent;
        }

        // CASO 3: pt is left child of its parent. Right-rotation required
        RightRotate(grand_parent_pt);
        int c = parent_pt->color;
        parent_pt->color = grand_parent_pt->color;
        grand_parent_pt->color = c;
        pt = parent_pt;
      }
    }

    // CASO B: Parent of pt is right child of grandparent of pt
    else
    {
      rbTree uncle_pt = grand_parent_pt->left;

      // CASO 1: Uncle of pt is also red. Recoloring is required
      if ((uncle_pt != NULL) && (uncle_pt->color == BLACK))
      {
        grand_parent_pt->color = RED;
        parent_pt->color = BLACK;
        uncle_pt->color = BLACK;
        pt = grand_parent_pt;
      }
      else
      {
        // CASO 2: pt is left child of its parent. Right-rotation is required
        if (pt == parent_pt->left)
        {
          RightRotate(parent_pt);
          pt = parent_pt;
          parent_pt = pt->parent;
        }

        // CASO 3: pt is right child of its parent. Left-rotation is required
        LeftRotate(grand_parent_pt);
        int c = parent_pt->color;
        parent_pt->color = grand_parent_pt->color;
        grand_parent_pt->color = c;
        pt = parent_pt;
      }
    }
  }
}

void Insert(int key)
{
  rbTree pt = NewNode(key);

  // Do a normal BST insert
  root = BSTInsert(root, pt);

  // Fix RB-Tree violations
  FixTree(root, pt);

  // Set the root to black
  root->color = BLACK;
}

void InorderTraversal(rbTree root)
{
  if (root == NULL)
    return;
  else
  {
    InorderTraversal(root->left);
    printf("%2d\t(", root->key);
    if (root->color == RED)
      printf("red)  \t");
    else
      printf("black)\t");
    if (root->parent == NULL)
    {
      printf("ROOT\n");
    }
    else
    {
      printf("Parent: %d (", root->parent->key);
      if (root->parent->color == RED)
        printf("red)\n");
      else
        printf("black)\n");
    }
    InorderTraversal(root->right);
  }
}

int main()
{
  Insert(3);
  Insert(14);
  Insert(6);
  Insert(1);
  Insert(18);
  Insert(15);
  Insert(20);
  Insert(16);
  InorderTraversal(root);

  return 0;
}
