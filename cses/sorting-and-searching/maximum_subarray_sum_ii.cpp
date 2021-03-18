#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;


void solve()
{
    int n, a, b; cin >> n >> a >> b;
    vector<long long> v(n);
    for(auto& vi : v) cin >> vi;

    long long currentSum = 0;
    // sum first a elements
    for(int i=0; i<a; ++i) currentSum += v[i];
    long long maxSum = currentSum;
    
    int start = 0;
    long long variableSum = 0;

    for(int end=a; end<n; ++end)
    {
        currentSum += v[end];

        if(end - start + 1 > b)
        {
            if(a != b) variableSum -= v[start];
            currentSum -= v[start];
            ++start;
        }

        if(variableSum <= 0)
        {
            currentSum -= variableSum;
            variableSum = 0;
            start = end - a;
        }

        int newVariable = v[end-a];
        if(variableSum + newVariable > 0 && a != b)
            variableSum += newVariable;
        else
        {
            currentSum = currentSum - variableSum - newVariable;
            variableSum = 0;
            start = end - a + 1;
        }


        maxSum = max(maxSum, currentSum);
        // cout << "----------\nend = " << end << endl
        //      << "start = " << start << endl
        //      << "totalLength = " << end - start + 1 << endl
        //      << "variableLength = " << end - start + 1 - a << endl
        //      << "newVariable = " << newVariable << endl
        //      << "variableSum = " << variableSum << endl
        //      << "currentSum = " << currentSum << endl;
    }
    cout << maxSum << endl;
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