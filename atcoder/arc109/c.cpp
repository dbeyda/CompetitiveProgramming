#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;

char rps(char first, char second)
{
    if (first == second) return first;
    if (first == 'R')
        return (second == 'P' ? 'P' : 'R');
    if (first == 'P')
        return (second == 'S' ? 'S' : 'P');
    if (first == 'S')
        return (second == 'R' ? 'R' : 'S');
    cout << "Error on rps(" << first << ", " << second << ")\n";
    exit(1);
}

void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    string t;
    while(k--)
    {
        t = s + s;
        for(int i=0; i<n; ++i)
            s[i] = rps((char) t[2*i], (char) t[2*i + 1]);
    }
    cout << s[0] << '\n';
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