#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_cases;
    cin >> n_cases;

    while(n_cases--)
    {
        int n, k;
        cin >> n >> k;
        if (n <= k) cout << "0\n";
        else
        {
            string s;
            cin >> s;
            // for(int i=0; i<n; i++)
            //     s[i] = getchar();
            cout << "vec1 ok" << '\n';

            vector<int> on(k, 0);
            vector<int> off(k, 0);
            for(int i=0; i<n; i++)
            {
                if(s[i%k] == '1') on[i%k]++;
                else off[i%k]++;
            }
            cout << "on/off ok" << '\n';
            int moves = 0;
            for(int i=0; i<k; i++)
                moves += min(on[i], off[i]);
            cout << moves << '\n';
        }
        1 0 0 1 0 0 1 0 0
        0 1 2 0 1 2 0 1 2 
    }
    return 0;
}