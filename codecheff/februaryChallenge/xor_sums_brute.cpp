#include <bits/stdc++.h>
using namespace std;
#define TRACE(x) x
#define WATCH(x) TRACE( cout << #x" = " << x << endl)
#define PRINT(x) TRACE(printf(x))

void buff() { ios::sync_with_stdio(false); cin.tie(nullptr); }


vector< int > elems = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1};

vector< int > subsets_per_size(11, 0);
vector< int > subsets_sum_per_size(11, 0);
vector<int> subsets_containing_bit(11, 0);

int main() {
    buff();
    
    int m = 4;
    for(int i = 1; i < 1024; ++i)
    {
        int count = __builtin_popcount(i);
        int x = 0; 
        for(int j = 0; j < 10; ++j) {
            if(i & (1 << j)) {
                x ^= elems[j];
            }
        }
        if(count <= m) subsets_containing_bit[j+1]++;
        subsets_per_size[count]++;
        subsets_sum_per_size[count] += x;
    }

    for(int i = 1; i <= 10; ++i) {
        TRACE( cout << "tamanho = " << i << endl; )
        WATCH(subsets_per_size[i]);
        WATCH(subsets_sum_per_size[i]);
        WATCH(subsets_containing_bit[i]);
        TRACE( cout << endl << endl; )
    }
    return 0;
}