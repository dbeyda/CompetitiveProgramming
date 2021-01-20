#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;


class Tower
{
public:
    int id;
    stack<int> disks;
    int size() const { return disks.size(); }
};

void move(int qty, Tower &from, Tower &to, Tower &other, vector<pair<int, int>> &moves)
{
    if (to.size() != 0 && from.disks.top() > to.disks.top())
    {
        cout << "!! Error !! Moving " << from.disks.top() << " from T" << from.id
             << " to T" << to.id << endl;
        exit(1);
    }
    if (qty == 1)
    {
        // cout << "> Moving " << from.disks.top() << " from T" << from.id
        //     << " to T" << to.id << endl;
        to.disks.push(from.disks.top());
        from.disks.pop();
        moves.push_back(make_pair(from.id, to.id));
    }
    else
    {
        move(qty-1, from, other, to, moves);
        move(1, from, to, other, moves);
        move(qty-1, other, to, from, moves);
    }
}

void solve()
{
    int n; cin >> n;
    Tower T1, T2, T3;
    T1.id = 1;
    T2.id = 2;
    T3.id = 3;
    for(int i=n; i>0; --i)
        T1.disks.push(i);

    vector<pair<int, int>> moves;
    move(T1.size(), T1, T3, T2, moves);

    cout << moves.size() << '\n';
    for(auto& p : moves)
        cout << p.first << " " << p.second << '\n';
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