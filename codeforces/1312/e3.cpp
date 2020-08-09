#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

void print_vec(vector<int> v) {
    for (auto i: v) std::cout << i << ' ';
    cout << '\n';
}


int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    vector<int> original_vec;
    int dp[1000][500];

    int el, n;   
    
    // getting number of elements in input vector
    cin >> n;

    // getting input vector
    for (int i=0; i<n; i++) {
        cin >> el;
        original_vec.push_back(el);
    }
    
    for (int i=0; i<1000; i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    
    for (int j=1; j<500; j++) {
        for(int i=0; i<1000; i++) {
            dp[i][j] = min(dp[i][j]
        }
    }

    cout << smallest << '\n';
    return 0;
}

/*
Memory limit exceeded with 
20
39 38 36 36 37 39 39 19 18 18 20 31 31 15 15 16 16 16 48 48

*/