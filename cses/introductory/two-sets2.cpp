#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <fstream>
#include <iomanip>
#include <iostream>

double eps = 1e-12;

using namespace std;

template <typename T>
void printSet(vector<T> &s)
{
    cout << s.size() << '\n';
    for(auto& el : s) cout << el << ' ';
    cout << endl;
}

void solve()
{
    long long n; cin >> n;
    vector<long long> set1;
    vector<long long> set2;
    // totalSum = n * (n+1) / 2; deve ser par
    // logo n * (n+1) deve ser divisível por 4
    // n * (n+1) % 4 == 0
    // caso 1 - (n+1) % 4 == 0 e consequentemente n % 4 == 3
    // caso 2 - n % 4 == 0

    long long totalSum = n * (n+1)/2;
    if(n % 4 == 0)
    {
        for(long long i=1; i<=n/2; ++i)
        {
            if(i & 1)
            {
                set1.push_back(i);
                set1.push_back(n+1-i);
            }
            else
            {
                set2.push_back(i);
                set2.push_back(n+1-i);
            }
        }
    }
    else if (n % 4 == 3)
    {
        long long firstSum=0;
        for(long long i=n; i>=1; --i)
        {
            if(firstSum + i <= totalSum/2)
            {
                firstSum += i;
                set1.push_back(i);
            }
            else set2.push_back(i);
        }
    }
    else
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    printSet(set1);
    printSet(set2);
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