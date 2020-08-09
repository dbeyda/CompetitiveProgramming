#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

vector<int> now;
vector<int> after;
vector<vector<int>> adj;
vector<long long> a;
vector<int> b;
long long ans = 0;


void dfs(int i)
{
    for(auto child : adj[i])
        dfs(child);
    ans += a[i];
    if (a[i] >= 0)
    {
        now.push_back(i);
        if (b[i] != -1) a[b[i]] += a[i];
    }
    else
        after.push_back(i);
}

void solve()
{
    int n;
    cin >> n;

    adj.resize(n);
    a.resize(n);
    b.resize(n);
    int x;

    for(auto& ai : a) cin >> ai;
    for(int i=0; i<n; i++)
    {
        cin >> x;
        if (x != -1)
        {
            x--;
            adj[x].push_back(i);
        }
        b[i] = x;
    }

    for(int i=0; i<n; i++)
        if (b[i] == -1)
            dfs(i);

    cout << ans << endl;

    // print order
    reverse(after.begin(), after.end());
    for(auto node : now) cout << node+1 << " ";
    for(auto node : after) cout << node+1 << " ";
    cout << endl;
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
