#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);


long long mod = 10e9+7;

constexpr int ms = 2e5 + 13;

long long fact[ms];
long long inv_fact[ms];

template <typename T>
T pow_mod(T a, T b, T mod) {
    T res = 1;
    while(b) {
        if(b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2ll;
    }
    return res;
}


template <typename T>
T inv_mod(T a, T mod) { return pow_mod<T>(a, mod - 2, mod); }


void pre_compute() {
    fact[0] = 1ll; inv_fact[0] = 1ll;
    for(long long i = 1; i < ms; ++i)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        inv_fact[i] = inv_mod<long long>(fact[i], mod);
    }
}


long long comb(long long a, long long b){
    if (a < b) {
        cout << "Error, param a needs to be > = b.\n";
        exit(1);
    }
    if (a==b || b == 0) return 1;
    long long den = (fact[a-b] * fact[b]) % mod;
    long long ans = (fact[a] * inv_mod<long long>(den, mod)) % mod;
    return ans;
}


void solve()
{
    int n;
    cin >> n;

    vector<int> freq(n+1, 0);
    vector<long long> finalFreq(n+1, 0);
    vector<int> a(n);
    for(auto& ai : a)
    {
        cin >> ai;
        freq[ai]++;
    }
    for(int i=0; i<=n; ++i)
    {
        int freqI = freq[i];
        if (!freqI) continue;
        while(freqI)
        {
            int partialI = 1;
            // compute number of ways to use j and still write i to the paper
            for(int j=0; j<=n; j++)
            {
                if ((freq[j] < 1) || j==i) continue;
                int limit = freqI;
                if (j < i) limit = freqI-1;
                int usableJ = min(limit, freq[j]);

                // compute number of different ways to use up to <limit> j
                int partialJ = 0;
                while(usableJ >= 0)
                {
                    partialJ += comb(freq[j], usableJ);
                    --usableJ;
                }
                partialI = (partialI % mod ) * (partialJ % mod) % mod;
            }
            // number of ways to use i freqI times
            partialI = (partialI % mod) * (comb(freq[i], freqI) % mod) % mod;
            finalFreq[i] = ((finalFreq[i] % mod) + partialI % mod) % mod;
            --freqI;
        }
    }


    for(auto& ai : a)
    {
        cout << finalFreq[ai] << " ";
        finalFreq[ai] = 0;
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pre_compute();

    int nCases;
    cin >> nCases;

    while(nCases--)
        solve();

    return 0;
}
