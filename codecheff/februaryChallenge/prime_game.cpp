#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;


vector<bool> prime(1e6+5, true);
vector<int> primes(1e6+5);

void sieveOfEratosthenes()
{
    prime[0] = false;
    prime[1] = false;
    int n = prime.size();
    for (int p = 2; p * p <= n; p++)
        if (prime[p] == true)
            for (int i = p * 2; i <= n; i += p)
                prime[i] = false;
    
    // count how many primes are <= i
    int pCount = 0;
    for(int i=0; i<n; ++i)
    {
        if(prime[i]) ++pCount;
        primes[i] = pCount;
    }
}


void solve()
{
    int x, y;
    cin >> x >> y;

    if(primes[x] <= y) cout << "Chef\n";
    else cout << "Divyam\n";
}

int main()
{
    sieveOfEratosthenes();
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