#include <stdio.h>

#define MAX 100

struct Node
{
    int data;
    int next;
};

int main()
{
    struct Node nodes[MAX];
    int head = -1, current = -1, count = 0, value, i;

    printf("Enter integers to add and 0 to stop:\n");
    while (count < MAX)
    {
        scanf("%d", &value);
        if (value == 0)
            break;

        nodes[count].data = value;
        nodes[count].next = -1;

        if (head == -1)
        {
            head = count;
            current = count;
        }
        else
        {
            nodes[current].next = count;
            current = count;
        }
        count++;
    }

    printf("\nLinked List :\n");
    i = head;
    while (i != -1)
    {
        printf("%d  ", nodes[i].data);
        i = nodes[i].next;
    }
    printf("0\n");

    return 0;
}
