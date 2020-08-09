#include <bits/stdc++.h>
#include <iostream>
#include <chrono> 


using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

long long mod = 998244353;
// long long mod = 1;


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

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);


    long long n, m;
    long long ans;
    cin >> n >> m;
    pre_compute();

    ans = (comb(m, n-1)% mod * (n-2) % mod ) % mod;
    long long acum = 0;
    for (long long i=0; i<=n-3; i++) {
        acum += comb(n-3, i) % mod;
    }
    ans *= acum % mod;
    cout << ans % mod << '\n';

    return 0;
}
