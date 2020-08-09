#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

int numTables(int start, int end, int k)
{
    int size = end + 1 - start;
    return (size-k) / (k+1);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    bool allZero = true;
    vector<char> v(n);
    for(auto& i : v) {
        cin >> i;
        if (i == '1') allZero = false;
    }
    if (n == 1) {
        cout << ((v[0] == '1') ? 0 : 1) << endl;
        return;
    }
    if (allZero)
    {
        cout << numTables(-k, n-1+k, k) << endl;
        return;
    }
    int total=0;
    int start=0;
    for(int i=0; i<n; i++)
    {
        if(v[i] == '1')
        {
            if (start == 0) start = -k;
            total += numTables(start, i-1, k);
            start = i+1;
        }
    }
    total += numTables(start, n-1+k, k);
    cout << total << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_cases;
    cin >> n_cases;

    while(n_cases--)
        solve();
    return 0;
}