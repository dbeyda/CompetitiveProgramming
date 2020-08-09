#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

void solve()
{
    long long n, d;
    cin >> n >> d;
    int points = 0;
    long long px, py;
    while (n--)
    {
        cin >> px >> py;
        if (sqrt(px*px + py*py) <= d)
            points++;
    }
    cout << points << '\n';

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
