#define ll long long;

#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
void applyOp(vector<long long> &a, long long maxx)
{
    for(auto& ai : a)
        ai = maxx - ai;
}

void solve()
{
    long long n, k, maxx, minn;
    maxx = -1e11;
    minn = 1e11;
    cin >> n >> k;
    vector<long long> a(n);
    for(auto& ai : a)
    {
        cin >> ai;
        maxx = max(maxx, ai);
        minn = min(minn, ai);
    }
    // apply once
    k--;
    applyOp(a, maxx);
    maxx = maxx - minn;

    if (n == 1)
    {
        cout << 0 << '\n';
        return;
    }
    if (k % 2)
        applyOp(a, maxx);
    for(auto& ai : a)
        cout << ai << " ";
    cout << '\n';
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
