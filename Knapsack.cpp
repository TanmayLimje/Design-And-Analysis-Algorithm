#include <iostream>
using namespace std;

void knapsack(int n, float weight[], float profit[], float capacity)
{
    float arr[n];
    int i;
    int c = capacity;
    float totalProfit = 0;

    for ( i = 0; i < n; i++)
    {
        arr[i] = 0;
    }

    for ( i = 0; i < n; ++i)
    {
        if (weight[i] > c)
            break;
        else
        {
            arr[i] = 1;
            totalProfit = totalProfit + profit[i];
            c = c - capacity;
        }
    }

    if (i < n)
        arr[i] = c / weight[i];

    totalProfit = totalProfit + (arr[i] * profit[i]);

    cout << "RESULT" << endl;
    for (i = 0; i < n; ++i)
    {
        cout << arr[i] << endl;
    }

    cout << "Total profit: " << totalProfit;


}

int main() {

    int n;
    float weight[n], profit[n], capacity, ratio[n];
    float temp;

    cout << "Enter no of items: ";
    cin >> n;

    cout << "Enter Weight and profit (w,p): " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> weight[i] >> profit[i];
    }

    cout << "Enter capacity: " ;
    cin >> capacity;
    
    for(int i = 0; i < n; i++)
        ratio[i] = profit[i] / weight[i];

    for (int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(ratio[i] < ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    knapsack(n,weight,profit,capacity);

    return 0;
}
