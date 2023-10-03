#include <bits/stdc++.h>
using namespace std;

struct bag
{
    double ratio;
    int price;
    int weight;
    int f;
};

bool compare(bag a, bag b)
{
    return (a.ratio>b.ratio);
}

class knapsack
{
private:

    int n, capacity, result;
    bag array[500];
    int val[500], wt[500];
    bool status = false;

public:
    void input();
    void display();
    void maxi();
    void greedy();
    void dynamic();
};

void knapsack::input() {
    int i = 0;
    cout << "Enter no of items: ";
    cin >> n;

    while(i < n)
    {
        int a,b;
        cout << "\nItem" << i+1 << ": Value and Weight: ";
        cin >> a >> b;

        if (a>0 && b>0)
        {
            val[i] = a;
            wt[i] = b;
            array[i].price = a;
            array[i].weight = b;
            array[i].ratio = (double)array[i].price/array[i].weight;
            i++;
        }

        else
            cout << "Enter valid value and weight!" << endl;
    }

    cout << "Enter the capacity of bag: ";
    cin >> capacity;

    while(capacity <0 )
    {
        cout << "Capacity cant be negative, please enter again!" << endl;
        cout << "Enter the capacity of bag: ";
        cin >> capacity;
    }

    cout << endl;
    status = true;
}

void knapsack::display() {
    if(!status)
    {
        cout << "Enter item into bag!" << endl;
        return;
    }

    cout << "------------------------------------------\n";
    cout << "\tValue" << "\tWeight" << endl;
    for (int i = 0; i < n; i++)
        cout << "\t" << val[i] << "\t" << wt[i] << endl;
    cout << "-------------------------------------------\n";
}

void knapsack::greedy() {
    if(!status)
    {
        cout << "Enter item into bag!" << endl;
        return;
    }

    int weight = capacity;
    sort(array,array+n,compare);
    //display();

    for (int i = 0; i < n; i++)
    {
        if (weight>array[i].weight)
        {
            result += array[i].price;
            weight -= array[i].weight;
            continue;
            array[i].f = 1;
        }

        array[i].f += array[i].ratio * weight;
        result += array[i].ratio * weight;
        break;
    }

    cout << "Greedy algo applied successfully!" << endl;
}

void knapsack::dynamic() {
    if(!status)
    {
        cout << "Enter item into bag!" << endl;
        return;
    }
    //int c = capacity+1;
    //int dp[] = {0};
    int dp[capacity + 1]={0};
    for (int i = 0; i < n; i++)
    {
        for(int w = capacity; w >= 0; w--)
        {
            if(wt[i] <= w)
            {
                dp[w] = max(dp[w],dp[w - wt[i]] + val[i]);
            }
        }
    }

    result = dp[capacity];
    cout << "Dynamic approach applied successfully!" << endl;
}

void knapsack::maxi() {
    cout << "\nMaximum value in knapsack: " << result << endl;

    cout << "------------------------------------------\n";
    cout << "\tValue" << "\tWeight" << "\tFraction" << endl;
    for (int i = 0; i < n; i++)
        cout << "\t" << val[i] << "\t" << wt[i] << "\t" << array[i].f <<  endl;
    cout << "-------------------------------------------\n";
}

int main ()
{
    int ch;
    knapsack k;

    cout << "--------- WELCOME ---------" << endl;

    while(1)
    {
        cout << "1. Input" << endl;
        cout << "2. Display" << endl;
        cout << "3. Greedy" << endl;
        cout << "4. Dynamic" << endl;
        cout << "5. Max possible value" << endl;
        cout << "6. exit" << endl;
        cout << "enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                k.input();
                break;
            case 2:
                k.display();
                break;
            case 3:
                k.greedy();
                break;
            case 4:
                k.dynamic();
                break;
            case 5:
                k.maxi();
                break;
            case 6:
                exit(0);
                break;
            default:
                cout << "Enter valid choice!!" << endl;
                break;
        }
    }

    return 0;
}
