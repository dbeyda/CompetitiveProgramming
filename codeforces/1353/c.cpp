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
        long long n;
        cin >> n;

        if(n == 1) cout << 0 << '\n';
        else
        {
            long long camadas = n/2;
            long long sum = 0;
            for(int i=0; i<camadas; i++)
            {
                long long lado = 3 + i*2;
                sum += (4*(lado) - 4) * (i+1);
            }
            cout << sum << '\n';
        }

    }
    return 0;
}