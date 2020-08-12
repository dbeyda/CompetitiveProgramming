#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<unsigned long long> a(n, 0);
    vector<unsigned long long> b(m, 0);

    for(auto& ai : a)
        cin >> ai;
    for (auto& bi : b)
        cin >> bi;

    unsigned int target = 0;
    while(target <= 1024)
    {
        bool validCombination = true;
        for(auto& ai : a)
        {
            bool validAi = false;
            for(auto& bj : b)
            {
                if (((ai & bj) | target) == target)
                {
                    validAi = true;
                    break;
                }
            }
            if (!validAi)
            {
                validCombination = false;
                break;
            }
        }
        if(validCombination)
        {
            cout << target << '\n';
            break;
        }
        ++target;
    }
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
