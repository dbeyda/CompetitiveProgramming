#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

#define add(x, y) x+y>=MOD?x+y-MOD:x+y


const long long mod = 998244353ll;
const int MOD = 998244353;
constexpr int ms = 1 << 18;

long long fact[ms];
long long inv_fact[ms];

template <typename T>
T modpow(T b, T e) {
	T ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

template <typename T>
T inv_mod(T a) { return modpow<T>(a, mod - 2); }

void pre_compute() {
    fact[0] = 1ll; inv_fact[0] = 1ll;
    for(long long i = 1; i < ms; ++i)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        inv_fact[i] = inv_mod<long long>(fact[i]);
    }
}

long long comb(long long a, long long b){
    if (a < b) {
        cout << "Error, param a needs to be > = b.\n";
        exit(1);
    }
    if (a==b || b == 0) return 1;
    long long den = (fact[a-b] * fact[b]) % mod;
    long long ans = (fact[a] * inv_mod<long long>(den)) % mod;
    return ans;
}

const int gen = 3; // use search() from PrimitiveRoot.cpp if MOD isn't 998244353
int bits[ms], root[ms];

long long fexp(long long x, long long e, long long mod = MOD) {
	long long ans = 1;
	x %= mod;
	for(; e > 0; e /= 2, x = x * x % mod) {
		if(e & 1) ans = ans * x % mod;
	}
	return ans;
}

void initFFT() {
	root[1] = 1;
	for(int len = 2; len < ms; len += len) {
		int z = (int) fexp(gen, (MOD - 1) / len / 2);
		for(int i = len / 2; i < len; i++) {
			root[2 * i] = root[i];
			root[2 * i + 1] = (int)((long long) root[i] * z % MOD);
		}
	}
}

void pre(int n) {
	int LOG = 0;
	while(1 << (LOG + 1) < n) {
		LOG++;
	}
	for(int i = 1; i < n; i++) {
		bits[i] = (bits[i >> 1] >> 1) | ((i & 1) << LOG);
	}
}

std::vector<int> fft(std::vector<int> a, bool inv = false) {
	int n = (int) a.size();
	pre(n);
	if(inv) {
		std::reverse(a.begin() + 1, a.end());
	}
	for(int i = 0; i < n; i++) {
		int to = bits[i];
		if(i < to) { std::swap(a[i], a[to]); }
	}
	for(int len = 1; len < n; len *= 2) {
		for(int i = 0; i < n; i += len * 2) {
			for(int j = 0; j < len; j++) {
				int u = a[i + j], v = (int)((long long) a[i + j + len] * root[len + j] % MOD);
				a[i + j] = add(u, v);
				a[i + j + len] = add(u, MOD - v);
			}
		}
	}
	if(inv) {
		long long rev = fexp(n, MOD-2, MOD);
		for(int i = 0; i < n; i++)
			a[i] = (int)(a[i] * rev % MOD);
	}
	return a;
}

std::vector<int> cut(const std::vector<int> &a, int n) {
	std::vector<int> b(n, 0);
	for(int i = 0; i < (int) a.size() && i < n; i++) {
		b[i] = a[i];
	}
	return b;
}

std::vector<int> operator *(std::vector<int> a, std::vector<int> b) {
	while(!a.empty() && a.back() == 0) a.pop_back();
	while(!b.empty() && b.back() == 0) b.pop_back();
	if(a.empty() || b.empty()) return std::vector<int>(0, 0);
	int n = 1;
	while(n-1 < (int) a.size() + (int) b.size() - 2) n += n;
	a.resize(n, 0);
	b.resize(n, 0);
	a = fft(a, false);
	b = fft(b, false);
	for(int i = 0; i < n; i++) {
		a[i] = (int) ((long long) a[i] * b[i] % MOD); 
	}
	return fft(a, true);
}


void solve()
{
    // computing fats and inv fats
    pre_compute();
    initFFT();
    // getting elements
    int n; cin >> n;
    vector<long long> v(n);
    for(auto& vi : v) cin >> vi;
    // computing in how many elements each bit is present
    vector<int> freq(32, 0);
    for(auto& vi : v)
        for(int i=0; i<32; ++i)
            if(vi & 1 << i) freq[i]++;
    
    // find A(x) and B(x) coeficients for each bit, for each length <= n
    vector<int> A(n+1, 0);
    vector<int> B(n+1, 0);
    vector<int> NNT;
    vector<vector<int>> cumulatedNNT(32);
    for(int bit = 0; bit < 32; ++bit)
    {
        A.assign(A.size(), 0);
        B.assign(B.size(), 0);
        int f = freq[bit];
        if(f == 0)
        {
            cumulatedNNT[bit] = vector<int>(n+1, 0);
            continue;
        }

        for(int ones = 0; ones <= n; ++ones)
        {
            if(ones % 2 && ones <= f) A[ones] = comb(f, ones);
            if(n-f >= ones) B[ones] = comb(n-f, ones);
        }
        NNT.clear();
        NNT = A * B;

        // cout << "BIT " << bit << endl;
        // cout << "A ";
        // for(auto& a : A[bit]) cout << a << " ";
        // cout << endl;
        // cout << "B ";
        // for(auto& b : B[bit]) cout << b << " ";
        // cout << endl;
        // cout << "C ";
        // for(auto& c : NNT[bit]) cout << c << " ";
        // cout << endl << endl;
        
        int cum = 0ll;
        for(int i=0; i<=n; ++i)
        {
            cumulatedNNT[bit].push_back((cum + NNT[i] % mod) % mod);
            cum = cumulatedNNT[bit].back();
        }
    }

    int ans[n+1];
    memset(ans, 0, (n+1)*sizeof(int));
    for(int m=0; m<n+1; ++m)
        for(int bit=0; bit<32; ++bit)
        {
            // cout << "Acessing bit " << bit << " // m " << m << endl;
            int contrib = ((cumulatedNNT[bit][m] % mod) * ((long long) pow(2, bit) % mod)) % mod; 
            ans[m] = (ans[m] + contrib) % mod;
        }

    int q; cin >> q;
    while(q--)
    {
        int m; cin >> m;
        // long long ans = 0ll;
        // for(int bit=0; bit<32; ++bit)
        // {
        //     // cout << "Acessing bit " << bit << " // m " << m << endl;
        //     long long contrib = ((cumulatedNNT[bit][m] % mod) * ((long long) pow(2, bit) % mod)) % mod; 
        //     ans = (ans + contrib) % mod;
        // }
        cout << ans[m] << endl;
    }
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

