#include <iostream>
using namespace std;

class Item
{
public:
    int weight;
    int profit;
};

int main()
{
    int n, capacity;
    Item item[100];

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter weight and profit of each item:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> item[i].weight >> item[i].profit;
    }

    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    // Sort according to profit/weight ratio
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double ratio1 = (double)item[i].profit / item[i].weight;
            double ratio2 = (double)item[j].profit / item[j].weight;

            if (ratio1 < ratio2)
            {
                Item temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    double totalProfit = 0;

    for (int i = 0; i < n; i++)
    {
        if (capacity >= item[i].weight)
        {
            capacity = capacity - item[i].weight;
            totalProfit = totalProfit + item[i].profit;
        }
        else
        {
            totalProfit = totalProfit +
                ((double)item[i].profit / item[i].weight) * capacity;

            capacity = 0;
            break;
        }
    }

    cout << "Maximum profit = " << totalProfit << endl;

    return 0;
}