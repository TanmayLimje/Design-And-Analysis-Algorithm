// N-Queen using backtracking

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int column, int N)
{
    int i,j;

    //same column check
    for(i = 0; i < column; i++)
    {
        if(board[row][i])
        {
            return false;
        }
    }

    //upper diagonal check
    for(i = row, j = column; i >= 0 && j >= 0; i--, j--)
    {
        if(board[i][j])
        {
            return false;
        }
    }

    //lower diagonal check
    for(i = row, j = column; i < N && j >= 0; i++, j--)
    {
        if(board[i][j])
        {
            return false;
        }
    }

    return true;
}

void printSol(const vector<vector<int>>& board)
{
    static int solutionCount = 0;

    cout << "Solution " << ++solutionCount << ":" << endl;

    for (const vector<int>& row : board)
    {
        for (int cell : row)
        {
            if (cell)
            {
                cout << "Q";
            }
            else
            {
                cout << ".";
            }
        }

        cout << "\n";
    }
}

bool nQueen(vector<vector<int>>& board, int column, int N)
{
    if (column >= N)
    {
        printSol(board);
        return false;
    }

    bool foundSol = false;

    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i , column, N))
        {
            board[i][column] = 1;
            foundSol = nQueen(board, column+1, N) || foundSol;
            board[i][column] = 0;
        }
    }

    return foundSol;
}

int main() {

    int N;
    cout << "Enter the size of Board: ";
    cin >> N;

    vector<vector<int>> board (N, vector<int>(N,0));

    if (!nQueen(board,0,N))
    {
        cout << "No solution found" << endl;
    }

    return 0;
}

/*

Enter the size of Board:5
 Solution 1:
Q....
...Q.
.Q...
....Q
..Q..
Solution 2:
Q....
..Q..
....Q
.Q...
...Q.
Solution 3:
..Q..
Q....
...Q.
.Q...
....Q
Solution 4:
...Q.
Q....
..Q..
....Q
.Q...
Solution 5:
.Q...
...Q.
Q....
..Q..
....Q
Solution 6:
....Q
..Q..
Q....
...Q.
.Q...
Solution 7:
.Q...
....Q
..Q..
Q....
...Q.
Solution 8:
....Q
.Q...
...Q.
Q....
..Q..
Solution 9:
...Q.
.Q...
....Q
..Q..
Q....
Solution 10:
..Q..
....Q
.Q...
...Q.
Q....

*/
