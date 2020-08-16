#define ll long long;

#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);


// main code
void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto& ai : a)
        cin >> ai;
    if (n == 1)
    {
        cout << 0 << '\n';
        return;
    }
    long long ops = 0;
    for(int i = n-1; i>0; --i)
    {
        if(a[i-1] > a[i])
        {
            ops += a[i-1] - a[i];
            a[i] += a[i-1] - a[i];
        }
    }
    cout << ops << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nCases = 1;
    cin >> nCases;

    while(nCases--)
        solve();

    return 0;
}
