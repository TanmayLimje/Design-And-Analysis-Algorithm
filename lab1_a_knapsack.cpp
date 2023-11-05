// 0/1 knapsack with dynamic programming

#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return (a>b) ? a:b;
}

void knapsack(int maxWeight, int profit[], int weight[], int size)
{
    int i,w;
    int k[size+1][maxWeight+1];
    bool selected[size + 1][maxWeight + 1];

    for(i = 0; i <= size; i++)
    {
        for(w = 0; w <= maxWeight; w++)
        {
            if (i == 0 || w == 0)
            {
                k[i][w] = 0;
                selected[i][w] = false;
            }

            else if (weight[i - 1] <= w)
            {
                k[i][w] = max(profit[i-1] + k[i-1][w-weight[i-1]] , k[i-1][w]);

                if (profit[i-1] + k[i-1][w-weight[i-1]] > k[i-1][w])
                {
                    selected[i][w] = true;
                }

                else
                {
                    selected[i][w] = false;
                }
            }

            else
            {
                k[i][w] = k[i-1][w];
                selected[i][w] = false;
            }
        }
    }

    int item = size;
    int remainingWeight = maxWeight;

    cout << "max profit = " << k[size][maxWeight] << endl;
    cout << "items selected: " << endl;

    while (item > 0 && remainingWeight > 0)
    {
        if(selected[item][remainingWeight])
        {
            cout << "item" << item << "(Profit:" << profit[item-1] << ",Weight:" << weight[item-1] << ")" << endl;
            remainingWeight -= weight[item-1];
        }
        item--;
    }

}

int main()
{

    int size = 0;
    cout << "Enter no of items:";
    cin >> size;

    int profit[size], weight[size];

    for(int i = 0; i < size; i++)
    {
        cout << "Enter the " << i+1 << " item profit value:";
        cin >> profit[i];

        cout << "Enter the " << i+1 << " item weight value:";
        cin >> weight[i];
    }

    int maxWeight = 0;
    cout << "Enter the max weight:";
    cin >> maxWeight;

    knapsack(maxWeight,profit,weight,size);

    return 0;
}

/*

Enter no of items:3
Enter the 1 item profit value:12
Enter the 1 item weight value:2
Enter the 2 item profit value:14
Enter the 2
item weight value:3
Enter the 3 item profit value:22
Enter the 3 item weight value:4
Enter the max weight:6
max profit = 34
items selected:
item3(Profit:22,Weight:4)
item1(Profit:12,Weight:2)

*/
