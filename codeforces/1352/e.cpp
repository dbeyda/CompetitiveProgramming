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
        vector<int> a(n+1, 0);
        for(int i=1; i<=n; i++)
            cin >> a[i];
        
        vector<int> specials(n+1, 0);
        vector<int> nCount(n+1, 0);

        vector<int> aAcum(n+1, 0);
        int totalSum = 0;
        for(int i=1; i<=n; i++)
        {
            totalSum += a[i];
            aAcum[i] = totalSum;
            nCount[a[i]]++;
        }

        int specialsSum = 0;
        for(int l=1; l<=n-1; l++)
            for(int r=l+1; r<=n; r++)
            {
                int sum = aAcum[r] - aAcum[l] + a[l];
                if ((sum <= n) && (nCount[sum]>0) && (specials[sum] == 0))
                {
                    specials[sum] = nCount[sum];
                    specialsSum += nCount[sum];
                }
            }
        cout << specialsSum << '\n';

    }
    return 0;
}