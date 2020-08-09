#include <bits/stdc++.h>
#include <iostream>
#include <chrono> 
#include <string>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

long long mod = 998244353;
// long long mod = 99999999999999999;
map<long long, long long> fact_cache;

long long fact(long long n) {
    cout << "[debug] [fact] startin fact " << n << endl;
    if (n == 0 || n == 1)
        return 1;
    // if (fact_cache.count(n))
    //     return fact_cache[n];
    long long f = 1;
    for(long long i=1; i <= n; i++)
        f = (f*i) % mod;
    cout << "[debug] [fact] finished fact " << n << ": " << f << endl;
    // fact_cache[n] = f;
    return f;
}

long long comb(int a, int b){
    if (a < b) {
        cout << "Error, param a needs to be > = b.\n";
        exit(1);
    }
    if (a==b || b == 0)
        return 1;
    cout << "[debug] [comb] startin " << a << ", " << b << endl;
    long long ans = (fact(a) % mod) / ( ((fact(a - b) % mod) * (fact(b) % mod)) % mod );
    cout << "[debug] [comb] finished " << a << ", " << b << endl;
    cout << "[debug] [comb] answer: " << ans << endl;
    return ans;
}

int main()
{

    string mode;
    cout << "Enter mode (fact | comb): ";
    cin >> mode;
    if (mode == "fact") {
        long long n;
        cin >> n;
        auto start = std::chrono::high_resolution_clock::now();
        long long ans = fact(n) % mod;
        auto stop = std::chrono::high_resolution_clock::now();
        cout << endl << "---------" << endl;
        cout << "Fat " << n << " = " << ans % mod << endl;
        cout << "Completed in " << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << endl;
    }
    else if (mode == "comb") {
        int n, m;
        cin >> n >> m;
        auto start = std::chrono::high_resolution_clock::now();
        long long ans = comb(n, m);
        auto stop = std::chrono::high_resolution_clock::now();
        cout << endl << "---------" << endl;
        cout << "comb " << n << ", " << m << " = " << ans << endl;
        cout << "Completed in " << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << endl;
    }
    return 0;
}
