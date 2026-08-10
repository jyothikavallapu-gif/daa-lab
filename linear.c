#include <stdio.h>

int main()
{
    int a[6] = {15, 3, 4, 6, 10, 12};
    int key;

    printf("Enter key to search: ");
    scanf("%d", &key);

    for (int i = 0; i < 6; i++)
    {
        if (a[i] == key)
        {
            printf("Key found at position %d\n", i);
            return 0;
        }
    }

    printf("Key not found\n");

    return 0;
}