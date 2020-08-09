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

    queue<vector<int>> q;
    vector<int> original_vec;

    int el, n;   
    
    // getting number of elements in input vector
    cin >> n;

    // getting input vector
    for (int i=0; i<n; i++) {
        cin >> el;
        original_vec.push_back(el);
    }
    
    int smallest = original_vec.size();
    q.push(original_vec);

    vector<int> vec;
    while (!q.empty()) {
        vec = q.front();
        q.pop();

        if (vec.size() < smallest)
            smallest = vec.size();

        for(int i=0; i<vec.size()-1; i++) {
            if (vec[i] == vec[i+1]) {
                vector<int> result(vec);
                result[i+1]++;
                result.erase(result.begin()+i);
                q.push(result);
            }
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