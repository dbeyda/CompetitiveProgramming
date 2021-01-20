#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;

void solve()
{
    int n; cin >> n;
    long long ans = 550;
    for(int i=1; i<=n; ++i)
    {
        if(i == 1) cout << "0\n";
        else if (i == 2) cout << "6\n";
        else if (i == 3) cout << "28\n";
        else if(i == 4) cout << "96\n";
        else if (i == 5) cout << "252\n";
        else if (i == 6) cout << "550\n";
        else
        {
            long long oldBoard = (i-1) * (i-1);
            // case where only one knight at new squares (excluding bottom-left corner)
            long long aux = 2*(oldBoard-2) + 2*(oldBoard-3) + max(0, i-5)*(oldBoard-4);
            // ans += 2 * aux / 2     dividing by 2 because the 2 knights are interchargeable
            ans += 2 * aux;
            // adding case one knight at bottom-left corner
            ans += i*i-3;
            // case both knights on new column or new row
            // ans += 2 * (i-1)*(i-2) / 2;
            ans += (i-1)*(i-2);
            // case where one knight in new column and one knight in new row
            ans += (i-1)*(i-1)-2;
            cout << ans << '\n';
        }
    }
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