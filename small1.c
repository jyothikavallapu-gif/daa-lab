#include <stdio.h>

int main()
{
    int a[100], n, k;
    int count, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    for (int i = 0; i < n; i++)
    {
        count = 0;

        for (int j = 0; j < n; j++)
        {
            if (a[j] < a[i])
            {
                count++;
            }
        }

        if (count == k - 1)
        {
            printf("%dth smallest element = %d\n", k, a[i]);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Kth smallest element not found\n");
    }

    return 0;
}