#include <stdio.h>

int main()
{
    int hash[10], n, key, index, i, j;

    for (i = 0; i < 10; i++)
        hash[i] = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &key);

        for (j = 0; j < 10; j++)
        {
            index = (key % 10 + j * j) % 10;

            if (hash[index] == -1)
            {
                hash[index] = key;
                break;
            }
        }
    }

    printf("Hash Table:\n");

    for (i = 0; i < 10; i++)
        printf("%d : %d\n", i, hash[i]);

    return 0;
}