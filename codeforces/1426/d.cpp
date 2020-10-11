#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);


void solve()
{
    // find subsequences with sum 0
    int n;
    cin >> n;

    vector<pair<int, int>> zeroPairs;
    long long sum = 0;
    unordered_map<int, vector<int>> m;
    m[0] = vector<int>({-1});
    for(int i=0; i<n; ++i)
    {
        long long num;
        cin >> num;
        sum += num;
        auto it = m.find(sum);
        if (it != m.end())
        {
            for(auto& begin : it->second)
                zeroPairs.push_back(make_pair(begin+1, i));
            it->second.push_back(i);
        }
        else m[sum] = vector<int>({0});
    }

    // find minimum number of insertions
    std::sort(zeroPairs.begin(), zeroPairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) -> bool
    {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });

    if (zeroPairs.size() == 0) cout << 0 << "\n";
    else
    {
        int count = 1;
        int insertion = zeroPairs[0].second;
        for(int i=1; i<zeroPairs.size(); ++i)
            if(zeroPairs[i].first >= insertion)
            {
                count++;
                insertion = zeroPairs[i].second;
            }
        cout << count << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_cases = 1;
    // cin >> n_cases;

    while(n_cases--) solve();
    return 0;
}