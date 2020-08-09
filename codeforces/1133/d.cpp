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
        int n;
        cin >> n;

        vector<int> a(n, 0);
        vector<int> b(n, 0);
        for(auto& i : a)
            cin >> i;
        for(auto& i : b)
            cin >> i;

        // count number of zeros in b (if d = 0, this will be the result)
        int zeros = 0;
        for(auto& i : b)
            if (!i) zeros++;

        // count most frequent (ai, bi) pair
        map<pair<int, int>, int> freq;
        for(int i=0; i<n; i++)
        {
            pair<int, int> p = make_pair(a[i], b[i]);
            if (freq.find(p) != freq.end())
                freq[p]++;
            else
                freq[p] = 1;
        }
        int aMax = a[0];
        int bMax = b[0];
        int freqMax = 1;
        for(auto it = freq.begin(); it != freq.end(); it++)
        {
            pair<int, int> key = it->first;
            int value = it->second;
            if (value > freqMax)
            {
                freqMax = value;
                aMax = key.first;
                bMax = key.second;
            }
        }
        cout << max(zeros, freqMax) << endl;

    }

    return 0;
}
