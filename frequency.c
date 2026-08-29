#include <stdio.h>

int main()
{
    int a[100], freq[100] = {0};
    int n, i, j;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n; i++)
        freq[a[i]]++;

    printf("Frequency:\n");

    for (i = 0; i < n; i++)
    {
        if (freq[a[i]] != 0)
        {
            printf("%d : %d\n", a[i], freq[a[i]]);

            for (j = i + 1; j < n; j++)
                if (a[j] == a[i])
                    freq[a[j]] = 0;
        }
    }

    return 0;
}