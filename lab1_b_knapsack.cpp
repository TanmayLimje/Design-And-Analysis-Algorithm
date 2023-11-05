// fractional knapsack

#include <bits/stdc++.h>

using namespace std;

struct Item{
    double profit;
    double weight;
    int index;
};

bool comparator(Item a, Item b)
{
    double ratio1 = (double)a.profit/ (double)a.weight;
    double ratio2 = (double)b.profit / (double)b.weight;
    return ratio1 > ratio2;
}

void knapsack(Item data[], int size, int maxWeight)
{
    Item sortedData[size];

    for(int i = 0; i < size; i++)
    {
        sortedData[i] = data[i];
    }

    sort(sortedData, sortedData + size, comparator);

    double maxValue = 0.0;

    cout << "Selected items: " << endl;

    for(int i = 0; i < size; i++)
    {
        if (data[i].weight <= maxWeight)
        {
            maxWeight -= data[i].weight;
            maxValue += data[i].profit;
            cout << "Item Index:" << data[i].index <<",profit:" << data[i].profit << ",Quantity:1" << endl;
        }
        else
        {
            double fractionalQuantity = (double)maxWeight / (double)data[i].weight;
            double fractionalProfitValue = ((double)data[i].profit) * ((double)fractionalQuantity);

            maxValue += fractionalProfitValue;

            cout << "Item Index:" << data[i].index <<",profit:" << fractionalProfitValue << ",Quantity:" << fractionalQuantity << endl;

            break;
        }
    }

    cout << "Max Profit: " << maxValue << endl;

}

int main()
{
    int size = 0;
    cout << "Enter the no of items: ";
    cin >> size;

    Item data[size];
    for(int i = 0; i < size; i++)
    {
        cout << "Enter the " << i << " item profit value: ";
        cin >> data[i].profit;

        cout << "Enter the " << i << " item weight value: ";
        cin >> data[i].weight;

        data[i].index = i;
    }

    int maxWeight = 0;
    cout << "Enter the max weight: ";
    cin >> maxWeight;

    knapsack(data,size,maxWeight);

    return 0;
}

/*

Enter No. of Items: 3
Enter the 0th item profit Value: 12
Enter the 0th item weight Value: 2
Enter the 1th item profit Value: 14
Enter the 1th item weight Value: 4
Enter the 2th item profit Value: 11
Enter the 2th item weight Value: 5
Enter the max weight: 10
Selected Items
Item index: 0, profit: 12, Quantity: 1
Item index: 1, profit: 14, Quantity: 1
Item index: 2, profit: 8.8, Quantity: 0.8
Max profit: 34.8

*/
