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
    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> people(n);
    vector<long long> flats(m);

    for(auto& pi : people) cin >> pi;
    for(auto& fi : flats) cin >> fi;

    sort(people.begin(), people.end());
    sort(flats.begin(), flats.end());

    long long ans = 0;
    int peopleIdx = 0;
    int flatsIdx = 0;
    while(peopleIdx < n && flatsIdx < m)
    {
        auto& p = people[peopleIdx];
        auto& f = flats[flatsIdx];
        
        if(p < f-k) ++peopleIdx;
        else if (p > f+k) ++flatsIdx;
        else
        {
            ++ans;
            ++flatsIdx;
            ++peopleIdx;
        }
    }
    cout << ans << '\n';
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