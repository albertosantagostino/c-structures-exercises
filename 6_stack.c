#include <stdio.h>
#include <stdlib.h>

struct StackArray
{
    int *elements;
    int max_size;
    int top;
};

typedef struct StackArray *stackarray;

stackarray CreateStackArray(int max_size)
{
    stackarray new_stackarray = (stackarray)malloc(sizeof(struct StackArray));
    new_stackarray->elements = (int *)malloc(sizeof(int) * max_size);
    new_stackarray->max_size = max_size;
    new_stackarray->top = -1;
}

void Push(stackarray sa, int element)
{
    if (sa->top == sa->max_size - 1)
    {
        printf("Cannot push on a filled stack!");
        return;
    }
    sa->elements[sa->top + 1] = element;
    sa->top++;
}

int Pop(stackarray sa)
{
    if (sa->top == -1)
    {
        printf("Cannot pop from an empty stack!");
        return 0;
    }
    int ret = sa->elements[sa->top];
    sa->elements[sa->top] = 0;
    sa->top--;
    return ret;
}

void PrintStack(stackarray sa)
{
    if (sa->top != -1)
    {
        for (int i = 0; i <= sa->top; i++)
        {
            printf("%d:\t%d\n", i, sa->elements[i]);
        }
    }
    else
    {
        printf("Empty!\n");
    }
}

int main()
{
    stackarray my_stackarray = CreateStackArray(5);
    Push(my_stackarray, 7);
    Push(my_stackarray, 98);
    Push(my_stackarray, 3);
    PrintStack(my_stackarray);
    int popped = Pop(my_stackarray);
    printf("Popped value is %d\n", popped);
    popped = Pop(my_stackarray);
    printf("Popped value is %d\n", popped);
    popped = Pop(my_stackarray);
    printf("Popped value is %d\n", popped);
    popped = Pop(my_stackarray);
    printf("Popped value is %d\n", popped);

    return EXIT_SUCCESS;
}