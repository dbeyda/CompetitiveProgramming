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
    vector<long long> len(n);
    for(auto& i : len)
        cin >> i;

    sort(len.rbegin(), len.rend());
    // cout << "sorted: ";
    // for(auto& i : len) cout << i << " ";
    // cout << endl;
    long long count = 0;
    for(int i=0; i<n-2; i++)
    {
        for(int j=i+1; j<n-1; j++)
        {
            if(len[i] == len[j]) continue;
            for(int k = j+1; k<n; k++)
            {
                if((len[k] == len[i]) || (len[k] == len[j])) continue;
                count += (len[i] < len[j] + len[k]);
                // cout << len[i] << " < " << len[j] << " + " << len[k] << "? " << (len[i] < len[j] + len[k]) << '\n';
            }
        }
    }
    cout << count << '\n';
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
