#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_cases;
    cin >> n_cases;

    while(n_cases--)
    {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        bool useTwoSquares = (2*x >= y);
        vector<vector<char>> vec(n, vector<char>(m));
        for(auto& line : vec)
            for(auto& square : line)
                cin >> square;
        int cost = 0;
        bool closedLast = false;
        for(auto& line : vec)
        {
            closedLast = false;
            for(auto& square : line)
            {
                if(square == '.')
                {
                    if(closedLast && useTwoSquares)
                    {
                        cost = cost - x + y;
                        closedLast = false;
                    }
                    else
                    {
                        cost += x;
                        closedLast = true;
                    }
                }
                else
                    closedLast = false;

            }
        }
        cout << cost << '\n';
    }
    return 0;
}