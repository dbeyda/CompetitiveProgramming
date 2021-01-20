#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;

bool decreasing_compare (const long long &first, const long long &second)
{
  return first > second;
}

void solve()
{
    int nTickets, nCust;
    cin >> nTickets >> nCust;
    list<long long> tickets;
    long long input;
    for(int i=0; i<nTickets; ++i)
    {
        cin >> input;
        tickets.push_back(input);
    }
    tickets.sort(decreasing_compare);
    

    for(int i=0; i<nCust; ++i)
    {
        cin >> input;
        bool found = false;
        for(auto it = tickets.begin(); it != tickets.end(); ++it)
        {
            if(*it <= input)
            {
                found = true;
                cout << *it << '\n';
                tickets.erase(it);
                break;
            }
        }
        if(!found) cout << "-1\n";
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