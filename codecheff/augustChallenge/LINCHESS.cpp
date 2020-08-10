#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for(auto& i : p)
        cin >> i;

    sort(p.rbegin(), p.rend());
    for(auto& pi : p)
    {
        if (k % pi == 0)
        {
            cout << pi << '\n';
            return;
        }
    }
    cout << "-1\n";
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
