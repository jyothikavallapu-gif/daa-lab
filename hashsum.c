#include <stdio.h>

int main()
{
    int hash[100], a[100];
    int n, T, i, index, needed;

    for (i = 0; i < 100; i++)
        hash[i] = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter target: ");
    scanf("%d", &T);

    for (i = 0; i < n; i++)
    {
        needed = T - a[i];

        index = needed % 100;

        if (index < 0)
            index = index + 100;

        if (hash[index] == needed)
        {
            printf("Pair found: %d + %d = %d\n",
                   needed, a[i], T);
            return 0;
        }

        hash[a[i] % 100] = a[i];
    }

    printf("No pair found\n");

    return 0;
}