// IMPORTANT
// the subarray has to be contiguous

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;


long long getSubarrays(int start, int end)
{
    long long n = end - start + 1;
    return (n * (n-1)) / 2 + n;
}


void solve()
{
    int n, k;
    cin >> n >> k;

    vector<long long> v(n);
    for(auto& vi : v) cin >> vi;

    if(k == 1)
    {
        cout << n << endl;
        return;
    }

    map<long long, int> freq;

    long long ans = 0;
    int start = 0;
    int end = -1;
    int oldEnd = -1;
    while(true)
    {
        // cout << "Loop\n";
        oldEnd = end;
        while((freq.count(v[end+1]) || (int) freq.size() < k) && end < n-1)
        {
            freq[v[end+1]]++;
            ++end;
        }
        // cout << "end is at " << end << endl;
        // add vectors to ans
        ans += getSubarrays(start, end);
        // cout << ans << endl;
        if(start <= oldEnd) ans -= getSubarrays(start, oldEnd);

        while((int) freq.size() == k && start < end)
        {
            --freq[v[start]];
            if(!freq[v[start]]) freq.erase(v[start]);
            ++start;
        }
        if(end == n-1) break;
    }
    cout << ans << endl;
    // cout << "oi" << endl;
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