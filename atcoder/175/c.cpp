
#define ll long long

#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

// 1e15 1e15 1e15

void solve()
{
    ll x, k, d;
    cin >> x >> k >> d;
    ll bestK = - llround((double)x/d);
    if (abs(bestK) < k)
    {
        x = x + bestK * d;
        k -= abs(bestK);
        if (k%2 == 0) cout << abs(x) << '\n';
        else cout << min(abs(x + d), abs(x - d)) << '\n';
    }
    else if(abs(bestK) >= k) cout << min(abs(x + k*d), abs(x - k*d)) << '\n';
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
