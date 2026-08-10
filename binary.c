#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    int a[100];

    printf("Enter the elements of the array (sorted):\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int key;
    printf("Enter key to search: ");
    scanf("%d", &key);

    int beg = 0, end = n - 1, mid;

    while (beg <= end)
    {
        mid = (beg + end) / 2;

        if (a[mid] == key)
        {
            printf("Key found at position %d\n", mid);
            return 0;
        }
        else if (key < a[mid])
        {
            end = mid - 1;
        }
        else
        {
            beg = mid + 1;
        }
    }

    printf("Key not found\n");

    return 0;
}
