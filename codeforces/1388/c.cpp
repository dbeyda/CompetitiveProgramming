#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

void solve()
{
    int n;
    cin >> n;

    vector<int> k;
    for(int i=0; i<n; i++)
       k.push_back(0b1001);

    for(int i=0; i<n/4; i++)
        k[n-1 -i] = 0;

    if (n%4)
    {
        k[n-1 -n/4] = k[n-1 -n/4] >> n%4;
        k[n-1 -n/4] = k[n-1 -n/4] << n%4;
    }

    for(int i=0; i<n; i++)
        cout << k[i];

   cout << endl;
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
