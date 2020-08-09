#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;

    int maxMatches=0, bestOffset=0;
    for(int offset=0; offset<n; offset++)
    {
        int matches=0;
        for(int pos=0; pos<n; pos++)
        {
            if (a[pos] == b[(pos+offset)%n])
                matches++;
        }
        if (matches > maxMatches)
        {
            maxMatches = matches;
            bestOffset = offset;
        }
        if (maxMatches >= ceil(float(n)/2.0f))
            break;
    }
    cout << maxMatches << endl;


    return 0;
}