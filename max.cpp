#include <iostream>
using namespace std;

void MaxMin(int A[], int low, int high, int &min, int &max)
{
    int mid;
    int min1, max1, min2, max2;

    if (low == high)
    {
        min = max = A[low];
    }
    else if (low == high - 1)
    {
        if (A[low] < A[high])
        {
            min = A[low];
            max = A[high];
        }
        else
        {
            min = A[high];
            max = A[low];
        }
    }
    else
    {
        mid = (low + high) / 2;

        MaxMin(A, low, mid, min1, max1);
        MaxMin(A, mid + 1, high, min2, max2);

        if (min1 < min2)
            min = min1;
        else
            min = min2;

        if (max1 > max2)
            max = max1;
        else
            max = max2;
    }
}

int main()
{
    int A[100], n;
    int min, max;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    MaxMin(A, 0, n - 1, min, max);

    cout << "Minimum element = " << min << endl;
    cout << "Maximum element = " << max << endl;

    return 0;
}
