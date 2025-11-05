#include <stdio.h>

int binarySearch(int *search, int n, int value)
{
    if (search == NULL || n == 0)
    {
        return 0;
    }

    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (search[mid] == value)
        {
            printf("Mid value: %d\n", search[mid]);
            printf("Found at index: %d\n", mid);
            return 1;
        }
        else if (value > search[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return 0;
}

int main()
{
    int n;
    printf("Enter number of elements : ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements in sorted order :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int searchVal;
    printf("Enter value to search: ");
    scanf("%d", &searchVal);

    int found = binarySearch(arr, n, searchVal);
    if (found)
        printf("Value %d found .\n", searchVal);
    else
        printf("%d NOT found in array.\n", searchVal);

    return 0;
}
