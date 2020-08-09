#include <bits/stdc++.h>
#include <iostream>
#include <list>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nCases = 1;

    while(nCases--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> d(n, 0);
        //vector<int> used(n, 0);
        for(auto& i : d)
            cin >> i;

        vector<int> modGroups(k, 0);
        for(int i=0; i<n; i++)
        {
            int m = d[i]%k;
            modGroups[m]++;
        }
        int maxBoxes = 0;
        // group mod 0 with itself
        int groupZero = modGroups[0] % 2 == 0 ? modGroups[0] : modGroups[0] - 1;
        maxBoxes += max(groupZero, 0);
        // group mod k/2 with itself
        if ((k % 2 == 0) && modGroups[k/2] != 0)
            maxBoxes += (modGroups[k/2] % 2 == 0? modGroups[k/2] : modGroups[k/2] - 1);

        int limit = (k % 2 == 0) ? k/2 : k/2 + 1;
        for(int i=1; i < limit; i++)
        {
            int firstGroup = modGroups[i] % 2 == 0? modGroups[i] : modGroups[i] - 1;
            int secondGroup = modGroups[k-i] % 2 == 0? modGroups[k-i] : modGroups[k-i] - 1;
            if (firstGroup > 0 && secondGroup > 0)
                maxBoxes += 2*min(firstGroup, secondGroup);
        }

        // int maxBoxes = 0;
        // for(int i=0; i<n-1; i++)
        // {
        //     if (used[i]) continue;
        //     for(int j = i+1; j < n; j++)
        //     {
        //         if (used[j]) continue;
        //         if (i == j) continue;
        //         if ((d[i] + d[j]) % k == 0)
        //         {
        //             used[i] = 1;
        //             used[j] = 1;
        //             maxBoxes+=2;
        //             break;
        //         }
        //     }
        // }
        cout << maxBoxes << endl;
    }

    return 0;
}
