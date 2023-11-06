// Travelling Sales Man Problem using least count branch and bound

#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

void reduceMatrix(vector<vector<int>>& costMatrix)
{
    int n = costMatrix.size();

    for(int i = 0; i < n; i++)
    {
        int minValue = INF;

        for(int j = 0; j < n; j++)
        {
            if (costMatrix[i][j] < minValue)
            {
                minValue = costMatrix[i][j];
            }
        }

        if (minValue != INF)
        {
            for (int j = 0; j < n; j++)
            {
                if (costMatrix[i][j] != INF)
                {
                    costMatrix[i][j] -= minValue;
                }
            }
        }
    }

    for (int j = 0; j < n; j++)
    {
        int minValue = INF;

        for(int i = 0; i < n; i++)
        {
            if(costMatrix[i][j] < minValue)
            {
                minValue = costMatrix[i][j];
            }
        }

        if(minValue != INF)
        {
            for( int i = 0; i < n; i++)
            {
                if (costMatrix[i][j] != INF)
                {
                    costMatrix[i][j] -= minValue;
                }
            }
        }
    }
}

void TSP(vector<vector<int>>& costMatrix, int & minCost, int level, int pathLength, vector<int>& path, vector<int>& minPath)
{
    int n = costMatrix.size();

    if (level == n)
    {
        pathLength += costMatrix[path[level-1]][path[0]];

        if (pathLength < minCost)
        {
            minCost = pathLength;
            minPath = path;
        }
        return ;
    }

    for (int i = 0; i < n; i++)
    {
        if (costMatrix[path[level-1]][i] != INF)
        {
            if (find(path.begin(),path.end(),i )== path.end())
            {
                int temp = costMatrix[path[level-1]][i];
                pathLength += temp;

                if (pathLength + (n-level)*temp < minCost)
                {
                    path[level] = i;
                    TSP(costMatrix,minCost,level+1,pathLength,path,minPath);
                }

                pathLength -= temp;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter no of cities:";
    cin >> n;

    vector<vector<int>> costMatrix (n, vector<int>((n)));

    cout << "Enter cost matrix: " << endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> costMatrix[i][j];

            if (costMatrix[i][j] == 0)
            {
                costMatrix[i][j] = INF;
            }
        }
    }

    vector<int> path (n);
    vector<int> minPath (n);
    int minCost = INF;

    reduceMatrix(costMatrix);
    path[0]=0;

    TSP(costMatrix,minCost,1,0,path,minPath);

    cout << "Optimal path: ";
    for (int i = 0; i < n; i++)
    {
        cout << minPath[i] << "->";
    }
    cout << minPath[0] << endl;

    cout << "Minimum cost : " << minCost << endl;

    return 0;
}

/*

Enter no of cities:4
Enter cost matrix:
0
4
1
9
3
0
6
11
4
1
0
2
6
5
-4
0
Optimal path: 0->1->2->3->0
Minimum cost : 16

*/
