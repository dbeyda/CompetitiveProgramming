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
