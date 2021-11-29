#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;

void recursiveFlip(vector<int>& v, int start, int end)
{
    int len = end - start + 1;
    if(len == 4)
        swap(v[end-1], v[end]);
    else if(len > 4)
    {
        int firstEnd = (start + end)/2; 
        recursiveFlip(v, start, firstEnd);
        recursiveFlip(v, firstEnd+1, end);
        reverse(v.begin()+firstEnd+1, v.begin()+end+1);
    }
}

void solve()
{
    int n; cin >> n;
    vector<int> ans(pow(2, n), 0);
    for(int i=0; i<ans.size(); ++i)
        ans[i] = i;
    recursiveFlip(ans, 0, ans.size()-1);
    for(auto& e : ans)
        cout << bitset<16>(e).to_string().substr(16-n, 16) << endl;
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
