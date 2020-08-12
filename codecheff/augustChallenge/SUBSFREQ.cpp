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

    vector<pair<int, int>> inputFreq;
    for(auto& ai : a)
        inputFreq.push_back(make_pair(ai, freq[ai]));

    sort(inputFreq.begin(), inputFreq.end(),
        [](pair<int, int>& a, pair<int, int>& b)
            {
                if (a.second == b.second) return a.first < b.first;
                return a.second > b.second;
            });

    cout << "Sorted frequencies: ";
    for(auto& p : inputFreq) cout << "<" << p.first << ", " << p.second << "> ";
    cout << endl;

    for(int i=0; i<n; i++)
    {
        finalFreq[inputFreq[i].first] = (finalFreq[inputFreq[i].first] % mod + pow_mod((long long)2, (long long)(n-1-i), mod)) % mod;
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
