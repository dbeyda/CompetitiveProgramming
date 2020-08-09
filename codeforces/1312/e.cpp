#include <bits/stdc++.h>
#include <iostream>
#include <chrono> 


using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

vector <int> v;


void solve(){
    int n = v.size();
    int i = 0;
    while (i < n-1) {
        if (v[i] == v[i+1]) {
            v[i]++;
            v.erase(v.begin() + i+1);
            return;
        }
        i++;
    }
}


int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);


    int a, n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a;
        v.push_back(a);
    }
    int v_size = 0;
    while (v_size != v.size()) {
        v_size = v.size();
        solve();
    }

    // for (auto i: v) std::cout << i << ' ';
    // cout << '\n';
    // cout << "min size: " << v.size() << '\n';
    cout << v.size() << '\n';
    return 0;
}

// fails for 
/*
fails for
15
67 67 65 65 66 66 66 68 67 67 67 65 65 66 70
67 67 66 66 66 66 68 67 67 67 66 66 70
67 67 66 66 66 66 68 67 67 67 67 70
67 67 67 67 68 67 67 70
68 68 68 68 70
69 69 70
70 70
71


answer: 2
*/

/*
15
67 67 65 65 66 66 66 68 67 67 67 65 65 66 70
67 67 66 66 66 66 68 67 67 67 66 66 70
67 67 67 67 68 67 67 67 67 70
68 68 68 68 68 70
>>> 69 69 68 70
>>> 70 68 70
68 69 69 70
68 70 70
68 71
*/

/*
67 67 65 65 66 66 66 68 67 67 67 65 65 66 70
67 67 66 66 66 66 68 67 67 67 66 66 70
67 67 67 67 68 67 67 67 67 70
68 68 68 68 68 70
68 69 69 70
68 70 70
68 71

*/