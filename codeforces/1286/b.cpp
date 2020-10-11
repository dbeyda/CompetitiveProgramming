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
    vector<pair<int, int>> v(n);        // [(i, num)] -> i = idx; num = value;
    for(int i=0; i<n; i++)
    {
        int num; cin >> num;
        v[i] = make_pair(i+1, num);
    }

    sort(v.rbegin(), v.rend(),
        [](pair<int, int>& a, pair<int, int>& b)
        { return a.second < b.second; });

    int sum = 0;
    for(int i=0; i<n; i++)
        sum += i * v[i].second + 1;

    cout << sum << '\n';
    for(auto& p : v)
        cout << p.first << " ";
    cout << '\n';
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
