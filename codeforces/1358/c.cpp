#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);



long long mod = 998244353;
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

long long arrj(long long a, long long b){
    if (a < b) {
        cout << "Error, param a needs to be > = b.\n";
        exit(1);
    }
    if (a==b || b == 0) return 1;
    long long den = (fact[a-b]) % mod;
    long long ans = (fact[a] * inv_mod<long long>(den, mod)) % mod;
    return ans;
}





long long square(long long ix, long long iy)
{
    double value, aux;
    double x = (double)ix + 1.0;
    double y = (double)iy + 1.0;
    // find value of (0, y)
    value = 1.0;
    aux = 1.0 + (y-2.0);
    aux = (1.0 + aux) * (y-1.0)/2.0;
    value += aux;

    // find value of (x, y) starting from (0, y)
    aux = (1.0 + y) + (x - 2.0);
    aux = ((1.0 + y) + aux) * (x - 1.0)/2.0;
    value += aux;

    if (value != (long long) value)
    {
        cout << "FAILED" << endl;
        exit(1);
    }
    return (long long) value;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_cases;
    cin >> n_cases;

    while(n_cases--)
    {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        x1--; y1--; x2--; y2--;

        long long down = x2-x1;
        long long right = y2 - y1;

        if(down == 0 || right == 0)
        {
            cout << 1 << endl;
            continue;
        }

        long long equals = 0;
        if ((down == right) && down % 2 == 1)
            equals = 1;

        cout << arrj(down + right, down) << endl;
    }
    return 0;
}