#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;

list<int>::iterator removeAndGetNext(list<int>& children, list<int>::iterator it)
{
    if(children.size() == 2)
    {
        children.erase(it);
        return children.begin();
    }

    auto toDelete = it;
    it = next(it);
    if(it == children.end()) it = children.begin();
    it = next(it);
    if(it == children.end()) it = children.begin();
    children.erase(toDelete);
    return it;
}

void solve()
{
    int n; cin >> n;
    list<int> children;
    for(int i=1; i<=n; ++i)
        children.push_back(i);

    auto nextChild = next(children.begin());
    while(!children.empty())
    {
        if(children.size() == 1)
        {
            cout << children.front() << endl;
            break;
        }
        cout << *nextChild << " ";
        nextChild = removeAndGetNext(children, nextChild);
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