#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

void solve()
{
    int n;
    cin >> n;
    vector<char> done(n, 0);
    vector<string> pin(n);
    unordered_set<string> pinSet;
    int changes = 0;

    for(auto &p : pin)
    {
        cin >> p;
        pinSet.insert(p);
    }

    for(int i = 0; i<n; i++)
    {
        if (done[i]) continue;
        for(int j=i+1; j < n; j++)
        {
            if (pin[i] == pin[j])
            {
                changes++;
                done[j] = 1;

                for(int k=0; k<4 && pin[i] == pin[j]; k++)
                {
                    for(int c='0'; c <= '9'; c++)
                    {
                        string attempt = pin[j];
                        attempt[k] = c;

                        if (!pinSet.count(attempt))
                        {
                            pin[j] = attempt;
                            pinSet.insert(attempt);
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << changes << '\n';
    for(auto &s : pin)
        cout << s << '\n';
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
