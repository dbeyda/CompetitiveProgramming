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
       int n;
        cin >> n;
        vector<int> result;
        int i=0;
        while(n > 0)
        {
            //cout << "n " << n << endl;
            int round = (n % 10) * pow(10, i);
            if (round)
                result.push_back(round);
            n = n / 10;
            i++;
        }
        cout << result.size() << '\n';
        for(auto& x : result)
            cout << x << ' ';
        cout << '\n';
    }
    return 0;
}