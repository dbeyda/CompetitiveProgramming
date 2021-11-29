#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;


void solve()
{
    int n, target;
    cin >> n >> target;
    target--;
    int dest[n-1];
    for(int i=0; i<n-1; ++i)
    {
        cin >> dest[i];
        dest[i] += i;
    }

    bool visited[n];
    memset(visited, false, sizeof(bool)*n);
    visited[0] = true;
    int curr = 0;
    while(true)
    {
        if(curr == target)
        {
            cout << "YES" << endl;
            return;
        }
        if(curr == n-1) break;
        if(visited[dest[curr]]) break;
        
        visited[dest[curr]] = true;
        curr = dest[curr];
        
    }
    cout << "NO" << endl;
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