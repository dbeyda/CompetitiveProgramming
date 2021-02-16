#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;


vector<bool> prime(1e6+1, true);
vector<int> primes;

void sieveOfEratosthenes()
{
    int n = prime.size();
    for (int p = 2; p * p <= n; p++)
        if (prime[p] == true)
        {
            for (int i = p * 2; i <= n; i += p)
                prime[i] = false;
        }
    
    prime[0] = false;
    prime[1] = false;
    for(int i=0; i<n; ++i)
        if(prime[i]) primes.push_back(i);
}

int countPrimeDivisors(int x)
{
    int ans = 0;
    for(auto& p : primes)
        if(x % p == 0)
            ++ans;
    return ans;
}

long long fat(int x)
{
    long long ans = 1;
    for(int i=1; i<=x; ++i) ans *= i;
    return ans;
}

void solve()
{
    int x, y;
    cin >> x >> y;
    int xFat = fat(x);
    cout << "-----------------\n";
    cout << "x = " << x << endl
         << "x! = " << xFat << endl
         << "y = " << y << endl;

    set<int> forbidden;
    vector<bool> win(xFat+1, true);
    win[0] = false;
    for(int i=2; i<=xFat; ++i)
        if(countPrimeDivisors(i) > y)
            forbidden.insert(i);
    
    cout << "y+1-esim prime = " << primes[y] << endl;
    // cout << "Forbidden set ";
    // for(auto& f : forbidden) cout << f << " ";
    // cout << endl;

    if(forbidden.size() == 0)
    {
        cout << "Chef\n";
        return;
    }

    win[*forbidden.begin()] = false;
    win[*next(forbidden.begin())] = false;
    for(auto it = next(forbidden.begin()); it != forbidden.end(); ++it)
    {
        auto i = *it;
        win[i] = false;
        for(auto jt = forbidden.begin(); jt != it; ++jt)
        {
            auto j = *jt;
            if (win[j] == false && forbidden.count(i-j) == 0)
            {
                win[i] = true;
                // cout << "win[" << i << "] = true with jump to "
                //      << j << ". win[" << j << "] = " << win[j]
                //      << endl;
                break;
            }
        }
    }

    if(win[xFat]) cout << "Chef\n";
    else cout << "Divyam\n";
    
    // for(int i=0; i<win.size(); ++i)
    //     if(!win[i]) cout << i << " - perde" << endl;

    // int xDivs = 0;
    // for(; xDivs < primes.size(); ++xDivs)
    //     if(primes[xDivs] > x) break;
    
    // if(xDivs <= y) cout << "Chef\n";
    // else cout << "Divyam\n";
}

int main()
{
    sieveOfEratosthenes(prime);
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