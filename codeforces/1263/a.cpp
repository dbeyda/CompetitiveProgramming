#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

void solve()
{
    int m1, m2, m3;
    cin >> m1 >> m2 >> m3;
    // sort
    if (m1 < m2) swap(m1, m2);
    if (m1 < m3) swap(m1, m3);
    if (m2 < m3) swap(m2, m3);

    int days = 0;
    if (m1 >= m2 + m3)
        days = m2 + m3;
    else
    {
        // make m1 equal to m2 by eating from m1 and m3
        // make m1=m2 equal to m3 by eating from m1 and m2;
        // here m1 = m2 = m3, eat the rest leaving either 0 or 1 candies.
        days = (m1 + m2 + m3) / 2;
    }
    cout << days << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nCases;
    cin >> nCases;

    while(nCases--)
        solve();

    return 0;
}
