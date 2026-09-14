#include <iostream>
#include <climits>
using namespace std;

int maxCrossingSum(int A[], int low, int mid, int high)
{
    int sum = 0;
    int leftSum = INT_MIN;

    for (int i = mid; i >= low; i--)
    {
        sum = sum + A[i];

        if (sum > leftSum)
            leftSum = sum;
    }

    sum = 0;
    int rightSum = INT_MIN;

    for (int i = mid + 1; i <= high; i++)
    {
        sum = sum + A[i];

        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

int maxSubarray(int A[], int low, int high)
{
    if (low == high)
        return A[low];

    int mid = (low + high) / 2;

    int leftMax = maxSubarray(A, low, mid);
    int rightMax = maxSubarray(A, mid + 1, high);
    int crossMax = maxCrossingSum(A, low, mid, high);

    if (leftMax >= rightMax && leftMax >= crossMax)
        return leftMax;
    else if (rightMax >= leftMax && rightMax >= crossMax)
        return rightMax;
    else
        return crossMax;
}

int main()
{
    int A[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    int result = maxSubarray(A, 0, n - 1);

    cout << "Maximum subarray sum = " << result << endl;

    return 0;
}
