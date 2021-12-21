#include <stdio.h>
#include <stdlib.h>

struct listE1
{
    int info;
    struct listE1 *next;
};

typedef struct listE1 *list;

void PrintList(list my_list)
{
    printf("[ ");
    while (my_list != NULL)
    {
        printf("%d ", my_list->info);
        my_list = my_list->next;
    }
    printf("]\n");
}

list GenerateList(int length)
{
    list head = NULL;
    head = (list)malloc(sizeof(struct listE1));
    head->info = 0;
    list last_node = head;
    for (int i = 1; i < length + 1; ++i)
    {
        list new_node = NULL;
        new_node = (list)malloc(sizeof(struct listE1));
        new_node->info = i;
        last_node->next = new_node;
        last_node = new_node;
    }
    return head;
}

// TODO: Reverse the list l and return its pointer
// list Reverse(list l)
// {
//
// }

// TODO: Write a function to count the number of elements in the list
// int GetLength(list l)
// {
//
// }

// TODO: Write a function to append a new element at the end of the list
// void AddValue(list l, int new_val)
// {
//
// }

// TODO: Write a function to delete the last element of the list
// void DeleteValue(list l)
// {
//
// }

int main()
{
    list abc = GenerateList(8);

    PrintList(abc);

    return 0;
}