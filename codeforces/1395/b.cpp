#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

void printPos(int x, int y)
{
    cout << x << " " << y << '\n';
}

void solve()
{
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;

    int x, y;
    x = sx; y = sy;
    printPos(sx, sy);

    // move to first row
    x = 1;
    printPos(x, y);
    // save this position as visited
    int ssx = x;
    int ssy = y;

    // move to first column
    x = 1; y = 1;
    // now we are at (1, 1)
    bool incr = true;
    while(x <= n)
    {
        while(true)
        {
            if(((x != sx) || (y != sy)) && ((x != ssx) || (y != ssy)))
                printPos(x, y);
            if ((y == m && incr) || (y == 1 && !incr))
            {
                incr = !incr;
                break;
            }
            else
            {
                if (incr) y++;
                else y--;
            }
        }
        x++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nCases = 1;
    // cin >> nCases;

    while(nCases--)
        solve();

    return 0;
}
