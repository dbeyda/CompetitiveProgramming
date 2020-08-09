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

    long long k = 0;
    for(int i=0; i<n; i++)
    {
       k = k << 4;
       k += 9;
    }

    k = k >> n;
    k = k << n;

    long long x = 0;
    for(int i=n-1; i>=0; i--)
    {
        long long mask = 0b1111 << 4*i;
        x *= 10;
        x += (k & mask) >> 4*i;
    }

   cout << x << endl;
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
