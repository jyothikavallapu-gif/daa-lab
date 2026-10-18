#include <stdio.h>

struct Node
{
    char ch;
    int freq;
    int left, right;
};

struct Node tree[20];
int n = 8, total = 0;

void huffman()
{
    int i, j, min1, min2, a, b;

    for (i = 0; i < n; i++)
    {
        tree[i].left = -1;
        tree[i].right = -1;
    }

    for (i = n; i < 2 * n - 1; i++)
    {
        min1 = min2 = 9999;
        a = b = -1;

        for (j = 0; j < i; j++)
        {
            if (tree[j].freq < min1 && tree[j].left == -1)
            {
                min2 = min1;
                b = a;
                min1 = tree[j].freq;
                a = j;
            }
            else if (tree[j].freq < min2 && tree[j].left == -1)
            {
                min2 = tree[j].freq;
                b = j;
            }
        }

        tree[i].freq = tree[a].freq + tree[b].freq;
        tree[i].ch = '#';
        tree[i].left = a;
        tree[i].right = b;

        tree[a].left = tree[a].left;
        tree[b].left = tree[b].left;
    }
}

void printCodes(int root, int code[], int top)
{
    if (tree[root].left == -1 && tree[root].right == -1)
    {
        printf("%c : ", tree[root].ch);

        for (int i = 0; i < top; i++)
            printf("%d", code[i]);

        printf("\n");
        total += tree[root].freq * top;
        return;
    }

    code[top] = 0;
    printCodes(tree[root].left, code, top + 1);

    code[top] = 1;
    printCodes(tree[root].right, code, top + 1);
}

int main()
{
    char ch[] = {'a', 'c', 'd', 'e', 'o', 'm', 's', 't'};
    int freq[] = {20, 11, 2, 10, 15, 8, 10, 22};
    int code[20];

    for (int i = 0; i < n; i++)
    {
        tree[i].ch = ch[i];
        tree[i].freq = freq[i];
        tree[i].left = -1;
        tree[i].right = -1;
    }

    huffman();

    printf("Huffman Codes:\n");
    printCodes(2 * n - 2, code, 0);

    printf("\nTotal memory required = %d bits (in hundreds)\n", total);
    printf("Actual memory required = %d bits\n", total * 100);

    return 0;
}
