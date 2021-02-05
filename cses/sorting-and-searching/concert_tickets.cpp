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

// changing to multiset<long long, greater<long long>> would make this much smaller.
void solve()
{
    int nTickets, nCust;
    cin >> nTickets >> nCust;
    multiset<long long> tickets;
    long long input;
    for(int i=0; i<nTickets; ++i)
    {
        cin >> input;
        tickets.insert(input);
    }

    for(int i=0; i<nCust; ++i)
    {
        cin >> input;

        // cout << "-------\nCust " << input << endl;
        
        auto it = tickets.lower_bound(input);
        auto rev = make_reverse_iterator(it);
        if(rev != tickets.rbegin()) --rev;
        // multiset<long long>::reverse_iterator rev;
        // if (it == tickets.end()) rev = tickets.rbegin();
        // else rev = make_reverse_iterator(it);
        
        // cout << "it " << *it << endl;
        // cout << "rev " << *rev << endl;


        bool found = false;
        while(rev != tickets.rend())
        {
            if(*rev <= input)
            {
                cout << *rev << endl;
                auto toRemove = rev;
                ++rev;
                tickets.erase(--toRemove.base());
                found = true;
                break;
            }
            else ++rev;
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