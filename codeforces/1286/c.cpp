#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

// test if (x, y) is inside the rectangle delimited by (x1, y1) and (x2, y2)
bool isInside(int x, int y, int x1, int y1, int x2, int y2)
{
    if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
        return true;
    return false;
}

void solve()
{
    int x1, y1, x2, y2,     // white sheet
        x3, y3, x4, y4,     // black sheet
        x5, y5, x6, y6;     // black sheet
    cin >> x1 >> y1 >> x2 >> y2
        >> x3 >> y3 >> x4 >> y4
        >> x5 >> y5 >> x6 >> y6;
    // test if all four white sheets edges are inside first black sheet
    if (   isInside(x1, y1, x3, y3, x4, y4)
        && isInside(x1, y2, x3, y3, x4, y4)
        && isInside(x2, y1, x3, y3, x4, y4)
        && isInside(x2, y2, x3, y3, x4, y4)
        ) cout << "NO\n";

    // test if all four white sheets edges are inside second black sheet
    else if (  isInside(x1, y1, x5, y5, x6, y6)
            && isInside(x1, y2, x5, y5, x6, y6)
            && isInside(x2, y1, x5, y5, x6, y6)
            && isInside(x2, y2, x5, y5, x6, y6)
            ) cout << "NO\n";

    // test if any of the four white sheet edges are visible
    else if (  (!isInside(x1, y1, x3, y3, x4, y4) && !isInside(x1, y1, x5, y5, x6, y6))
            || (!isInside(x1, y2, x3, y3, x4, y4) && !isInside(x1, y2, x5, y5, x6, y6))
            || (!isInside(x2, y1, x3, y3, x4, y4) && !isInside(x2, y1, x5, y5, x6, y6))
            || (!isInside(x2, y2, x3, y3, x4, y4) && !isInside(x2, y2, x5, y5, x6, y6))
            ) cout << "YES\n";
    // test if there is a space between both black squares
    else
    {
        // get x3, x4 to be the square with left most x
        if (x5 < x3)
        {
            swap(x3, x5);
            swap(y3, y5);
            swap(x4, x6);
            swap(y4, y6);
        }
        // test for horizontal spaces
        if (x4 < x5)
        {
            cout << "YES\n"; return;
        }
        // get y3, y4 to be the square with bottom most y
        if (y5 < y3)
        {
            swap(x3, x5);
            swap(y3, y5);
            swap(x4, x6);
            swap(y4, y6);
        }
        // test for horizontal spaces
        if (y4 < y5)
        {
            cout << "YES\n"; return;
        }
        cout << "NO\n";
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
