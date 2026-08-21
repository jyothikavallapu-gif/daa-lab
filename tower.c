#include <stdio.h>

void move(int disk, char src, char des)
{
    printf("Move disk %d from %c to %c\n", disk, src, des);
}

int main()
{
    int n, i, total = 1;
    int A[20], B[20], C[20];
    int topA, topB, topC;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    topA = n - 1;
    topB = -1;
    topC = -1;

    for (i = 0; i < n; i++)
        A[i] = n - i;

    for (i = 1; i <= n; i++)
        total = total * 2;

    total = total - 1;

    for (i = 1; i <= total; i++)
    {
        if (i % 3 == 1)
        {
            if (topA >= 0 && (topC < 0 || A[topA] < C[topC]))
            {
                C[++topC] = A[topA];
                move(A[topA], 'A', 'C');
                topA--;
            }
            else
            {
                A[++topA] = C[topC];
                move(C[topC], 'C', 'A');
                topC--;
            }
        }
        else if (i % 3 == 2)
        {
            if (topA >= 0 && (topB < 0 || A[topA] < B[topB]))
            {
                B[++topB] = A[topA];
                move(A[topA], 'A', 'B');
                topA--;
            }
            else
            {
                A[++topA] = B[topB];
                move(B[topB], 'B', 'A');
                topB--;
            }
        }
        else
        {
            if (topB >= 0 && (topC < 0 || B[topB] < C[topC]))
            {
                C[++topC] = B[topB];
                move(B[topB], 'B', 'C');
                topB--;
            }
            else
            {
                B[++topB] = C[topC];
                move(C[topC], 'C', 'B');
                topC--;
            }
        }
    }

    return 0;
}