#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    struct Node *temp;

    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    temp = top;
    printf("Deleted: %d\n", top->data);

    top = top->next;
    free(temp);
}

void display()
{
    struct Node *temp = top;

    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);

    printf("Stack: ");
    display();

    pop();

    printf("After pop: ");
    display();

    return 0;
}