#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow!  %d\n", value);
        return;
    }
    stack[++top] = value;
    printf("%d pushed \n", value);
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! \n");
        return -1;
    }
    return stack[top--];
}

void checkPalindrome()
{
    int n, i, temp;
    int arr[MAX];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    temp = -1;
    int tempStack[MAX];

    for (i = 0; i < n; i++)
    {
        tempStack[++temp] = arr[i];
    }

    int isPalindrome = 1;
    for (i = 0; i < n; i++)
    {
        if (arr[i] != tempStack[temp--])
        {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome)
        printf("The sequence is a Palindrome\n");
    else
        printf("The sequence is NOT a Palindrome\n");
}

void display()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack elements :\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\nSTACK MENU \n");
        printf("1. Push \n");
        printf("2. Pop \n");
        printf("3. Check Palindrome\n");
        printf("4. Display Stack \n");
        printf("5. Exit\n");
        printf("Enter  choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            value = pop();
            if (value != -1)
                printf("Popped: %d\n", value);
            break;
        case 3:
            checkPalindrome();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exit\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
