#include <stdio.h>
#include <stdlib.h>

#define MAX 5

char queue[MAX];
int front = -1;
int rear = -1;

void insert(char value)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow! \n");
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    queue[++rear] = value;
    printf("'%c' inserted \n", value);
}

char delete()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow! \n");
        return '\0';
    }

    char value = queue[front++];

    if (front > rear)
    {
        front = rear = -1;
    }

    return value;
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements:\n");
    for (int i = front; i <= rear; i++)
    {
        printf("'%c' ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int choice;
    char value;

    while (1)
    {
        printf("\nQUEUE MENU \n");
        printf("1. Insert \n");
        printf("2. Delete \n");
        printf("3. Display Queue \n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter character to insert: ");
            scanf(" %c", &value);
            insert(value);
            break;
        case 2:
            value = delete();
            if (value != '\0')
                printf("deleted: '%c'\n", value);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("exti\n");
            exit(0);
        default:
            printf("Invalid choice! .\n");
        }
    }

    return 0;
}
