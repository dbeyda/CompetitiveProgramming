#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>


using namespace std;


void solve()
{
    int b, n;
    cin >> b >> n;
    vector<pair<long long, long long>> items(n); // <size, value>
    for(auto& i : items) cin >> i.first >> i.second;
    
    long long maxValue[b+1][n+1];
    for(int i=0; i<=b; ++i) maxValue[i][0] = 0ll;
    for(int i=0; i<=n; ++i) maxValue[0][i] = 0ll;

    for(int i=1; i<=n; ++i)
        for(int bi=1; bi<=b; ++bi)
        {
            long long weight = items[i-1].first;
            long long value = items[i-1].second;

            maxValue[bi][i] = maxValue[bi][i-1];
            
            if(weight <= bi)
                maxValue[bi][i] = max(maxValue[bi][i],
                                      maxValue[bi-weight][i-1] + value);
        	
        }
    
    cout << maxValue[b][n] << endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
         freopen("../../input.txt", "r", stdin);
         freopen("../../output.txt", "w+", stdout);
     #endif
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long t=1;
    // cin >> t;
    for(int it=1; it<=t; it++)
        solve();
    return 0;
}