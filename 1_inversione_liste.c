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
    head = (struct listE1 *)malloc(sizeof(struct listE1));
    head->info = 0;
    list last_node = head;
    for (int i = 1; i < length + 1; ++i)
    {
        list new_node = NULL;
        new_node = (struct listE1 *)malloc(sizeof(struct listE1));
        new_node->info = i;
        last_node->next = new_node;
        last_node = new_node;
    }
    return head;
}

int main()  
{
    list abc = GenerateList(3);

    PrintList(abc);

    return 0;
}