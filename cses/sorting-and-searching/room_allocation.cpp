#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;

// To compare two pairs
class myComparator
{
public:
    int operator() (const pair<long long, long long>& p1, const pair<long long, long long>& p2)
    {
        return p1.first > p2.first;
    }
};

void solve()
{
    int n; cin >> n;
    vector<tuple<long long, long long, int, int>> v(n); // start, finish, input order, assigned room
    for(int i=0; i<n; ++i) 
    {
        long long a, b;
        cin >> a >> b;
        v[i] = make_tuple(a, b, i, 0);
    }

    sort(v.begin(), v.end(),
        [] (auto& a, auto& b) { return (get<0>(a) == get<0>(b)) ? (get<1>(a) < get<1>(b)) : (get<0>(a) < get<0>(b)); });
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, myComparator> heap;
    
    for(auto& vi : v)
    {
        if(heap.empty())
        {
            heap.push(make_pair(get<1>(vi), 1));
            get<3>(vi) = 1;
            continue;
        }

        auto bestRoom = heap.top();
        if(bestRoom.first < get<0>(vi))
        {
            heap.pop();
            heap.push(make_pair(get<1>(vi), bestRoom.second));
            get<3>(vi) = bestRoom.second;
        }
        else
        {
            int newRoom = heap.size()+1;
            heap.push(make_pair(get<1>(vi), newRoom));
            get<3>(vi) = newRoom;
        }
    }
    sort(v.begin(), v.end(),
        [] (auto& a, auto& b) { return get<2>(a) < get<2>(b); });
    
    cout << heap.size() << endl;
    for(auto& vi : v) cout << get<3>(vi) << " ";
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
    // cin >> t;
    for(int it=1; it<=t; it++)
        solve();
    return 0;
}