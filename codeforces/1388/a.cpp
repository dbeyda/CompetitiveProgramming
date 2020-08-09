#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

void solve()
{
    int n, x1, x2, x3, x4;
    cin >> n;

    int dif = n - 30;
    // smallest possible number is 6 + 10 + 14 + 1 = 31
    if (n < 31)
        cout << "NO\n";
    else {
        cout << "YES\n";
        if (dif == 6)
            cout << "6 15 14 1" << endl;
        else if (dif == 10)
            cout << "6 15 14 5" << endl;
        else if (dif == 14)
            cout << "6 10 21 7" << endl;
        else
            cout << "6 10 14 " << dif << endl;
    }
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
