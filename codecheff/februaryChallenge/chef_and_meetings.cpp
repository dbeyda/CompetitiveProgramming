#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;


int time(string s, string am)
{
    int result = 0;
    int hours, minutes;
    sscanf(s.c_str(), "%d:%d", &hours, &minutes);
    if(hours == 12) hours = 0;
    if(am[0] == 'P') hours += 12;
    return hours * 60 + minutes;
}


void solve()
{
    string s, am;
    cin >> s >> am;
    int meetingTime = time(s, am);

    int n; cin >> n;
    while(n--)
    {
        cin >> s >> am;
        int start = time(s, am);
        cin >> s >> am;
        int end = time(s, am);
        if(meetingTime < start || meetingTime > end) cout << 0;
        else cout << 1;
    }
    cout << endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt", "r", stdin);
        freopen("../../output.txt", "w+", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long t=1;
    cin >> t;
    for(int it=1; it<=t; it++)
        solve();
    return 0;
}