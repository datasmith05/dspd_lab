#include <stdio.h>

int main()
{
    int n;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);

    int arr[n];
    int odd = 0,even = 0;

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if ((i + 1) % 2 == 0)
        { 
            odd += arr[i];
        }
        else
        { 
             even+= arr[i];
        }
    }

    printf("Sum of no. at odd positions: %d\n",odd);
    printf("Sum of no. at even positions: %d\n", even);

    return 0;
}
