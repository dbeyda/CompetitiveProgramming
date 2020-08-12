#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

int n, m;
vector<unsigned long long> cumulatedOR;
vector<unsigned long long> a;
vector<unsigned long long> b;
unsigned long long minFound = ULLONG_MAX;
vector<unsigned long long> cis(1024+1, 0);

void rec(int i)
{
    unordered_set<unsigned long long> seen;
    for(int j=0; j<m; j++)
    {
        unsigned long long ci = (a[i] & b[j]);
        if (i == 0)
            cumulatedOR[i] = ci;
        else
            cumulatedOR[i] = cumulatedOR[i-1] | ci;

        if (seen.count(cumulatedOR[i])) continue;
        seen.insert(cumulatedOR[i]);

        if (i == (n-1))
            minFound = min(minFound, cumulatedOR[i]);
        else
        {
            cis[ci]++;
            rec(i+1);
            cis[ci]--;

            if (ci == 0 || cis[ci] > 0)
                break;
        }
    }
}

void solve()
{
    cin >> n >> m;
    a = vector<unsigned long long> (n, 0);
    b = vector<unsigned long long> (m, 0);
    cumulatedOR = vector<unsigned long long>(n, -1);

    for(auto& ai : a)
        cin >> ai;
    for (auto& bi : b)
        cin >> bi;

    rec(0);
    cout << minFound << '\n';
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
