#include <stdio.h>

struct Node
{
    char ch;
    int freq;
    int left, right;
    int used;
};

struct Node tree[20];

void printCodes(int root, int code[], int top, int n)
{
    if (tree[root].left == -1 && tree[root].right == -1)
    {
        printf("%c : ", tree[root].ch);

        for (int i = 0; i < top; i++)
            printf("%d", code[i]);

        printf("\n");
        return;
    }

    code[top] = 0;
    printCodes(tree[root].left, code, top + 1, n);

    code[top] = 1;
    printCodes(tree[root].right, code, top + 1, n);
}

int main()
{
    char ch[] = {'a', 'c', 'd', 'e', 'o', 'm', 's', 't'};
    int freq[] = {20, 11, 2, 10, 15, 8, 10, 22};
    int n = 8, i, j, a, b, code[20];
    int total = 0;

    for (i = 0; i < n; i++)
    {
        tree[i].ch = ch[i];
        tree[i].freq = freq[i];
        tree[i].left = tree[i].right = -1;
        tree[i].used = 0;
    }

    for (i = n; i < 2 * n - 1; i++)
    {
        int min1 = 9999, min2 = 9999;
        a = b = -1;

        for (j = 0; j < i; j++)
        {
            if (!tree[j].used && tree[j].freq < min1)
            {
                min2 = min1;
                b = a;
                min1 = tree[j].freq;
                a = j;
            }
            else if (!tree[j].used && tree[j].freq < min2)
            {
                min2 = tree[j].freq;
                b = j;
            }
        }

        tree[a].used = 1;
        tree[b].used = 1;

        tree[i].ch = '#';
        tree[i].freq = tree[a].freq + tree[b].freq;
        tree[i].left = a;
        tree[i].right = b;
        tree[i].used = 0;
    }

    printf("Huffman Codes:\n");
    printCodes(2 * n - 2, code, 0, n);

    return 0;
}