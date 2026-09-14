#include <iostream>
using namespace std;

class Matrix
{
public:
    int a[10][10];
};

void add(Matrix A, Matrix B, Matrix &C, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C.a[i][j] = A.a[i][j] + B.a[i][j];
        }
    }
}

void subtract(Matrix A, Matrix B, Matrix &C, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C.a[i][j] = A.a[i][j] - B.a[i][j];
        }
    }
}

void strassen(Matrix A, Matrix B, Matrix &C, int n)
{
    if (n == 1)
    {
        C.a[0][0] = A.a[0][0] * B.a[0][0];
        return;
    }

    int k = n / 2;

    Matrix A11, A12, A21, A22;
    Matrix B11, B12, B21, B22;

    Matrix M1, M2, M3, M4, M5, M6, M7;
    Matrix T1, T2;

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            A11.a[i][j] = A.a[i][j];
            A12.a[i][j] = A.a[i][j + k];
            A21.a[i][j] = A.a[i + k][j];
            A22.a[i][j] = A.a[i + k][j + k];

            B11.a[i][j] = B.a[i][j];
            B12.a[i][j] = B.a[i][j + k];
            B21.a[i][j] = B.a[i + k][j];
            B22.a[i][j] = B.a[i + k][j + k];
        }
    }

    add(A11, A22, T1, k);
    add(B11, B22, T2, k);
    strassen(T1, T2, M1, k);

    add(A21, A22, T1, k);
    strassen(T1, B11, M2, k);

    subtract(B12, B22, T2, k);
    strassen(A11, T2, M3, k);

    subtract(B21, B11, T2, k);
    strassen(A22, T2, M4, k);

    add(A11, A12, T1, k);
    strassen(T1, B22, M5, k);

    subtract(A21, A11, T1, k);
    add(B11, B12, T2, k);
    strassen(T1, T2, M6, k);

    subtract(A12, A22, T1, k);
    add(B21, B22, T2, k);
    strassen(T1, T2, M7, k);

    Matrix C11, C12, C21, C22;

    add(M1, M4, T1, k);
    subtract(T1, M5, T2, k);
    add(T2, M7, C11, k);

    add(M3, M5, C12, k);

    add(M2, M4, C21, k);

    subtract(M1, M2, T1, k);
    add(T1, M3, T2, k);
    add(T2, M6, C22, k);

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            C.a[i][j] = C11.a[i][j];
            C.a[i][j + k] = C12.a[i][j];
            C.a[i + k][j] = C21.a[i][j];
            C.a[i + k][j + k] = C22.a[i][j];
        }
    }
}

int main()
{
    Matrix A, B, C;
    int n;

    cout << "Enter order of matrix: ";
    cin >> n;

    cout << "Enter elements of first matrix:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A.a[i][j];
        }
    }

    cout << "Enter elements of second matrix:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> B.a[i][j];
        }
    }

    strassen(A, B, C, n);

    cout << "Resultant matrix:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << C.a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}