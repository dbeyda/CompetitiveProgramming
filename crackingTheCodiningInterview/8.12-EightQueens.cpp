#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GRID_SIZE = 8;

bool isValid(vector<int>& columns, int row, int col)
{
    for(int chosenRow=0; chosenRow < row; ++chosenRow)
    {
        int chosenCol = columns[chosenRow];
        if (chosenCol == col) return false;
        if (abs(chosenCol - col) == abs(chosenRow - row)) return false;
    }
    return true;
}

void queens(int row, vector<int>& columns, vector<vector<int>>& answer)
{
    if(row == GRID_SIZE)
        answer.push_back(columns);
    else
    {
        // for each column, if its valid, place a queen there
        for(int col=0; col<GRID_SIZE; col++)
        {
            if (isValid(columns, row, col))
            {
                columns[row] = col;
                queens(row+1, columns, answer);
            }
        }
    }
}

vector<vector<int>> queens()
{
    vector<vector<int>> answer;
    vector<int> columns(GRID_SIZE, 0);
    queens(0, columns, answer);
    return answer;
}

int main()
{
    vector<vector<int>> answer;
    answer = queens();
    for(auto& a : answer)
    {
        for(auto& q : a)
        {
            for(int i=0; i<q; ++i) cout << "| ";
            cout << "|q|";
            for(int i=q+1; i<GRID_SIZE; i++) cout << " |";
            cout << "\n";
        }
        cout << "------------------------\n";
    }

    return 0;
}
