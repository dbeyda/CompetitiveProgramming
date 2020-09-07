#include <iostream>
#include <vector>

using namespace std;

int magicIndexDistincts(vector<int>& v, int start, int end)
{
    // code for when sequence of integers have no repeated values
    if (start > end) return -1;
    int mid = (start + end) / 2;
    if (v[mid] == mid) return mid;
    if (v[mid] > mid) return magicIndexDistincts(v, start, mid-1);
    return magicIndexDistincts(v, mid+1, end);
}

int magicIndexRepeated(vector<int>& v, int start, int end)
{
    // improved code for when sequence of integer have repeated values
    if (start > end) return -1;
    int mid = (start + end) / 2;
    if (v[mid] == mid) return mid;

    // search left
    int idxLeft = magicIndexRepeated(v, start, min(v[mid], mid-1));
    // search right
    int idxRight = magicIndexRepeated(v, max(v[mid], mid+1), end);
    return max(idxLeft, idxRight);
}

int magicIndex(vector<int>& v)
{
    return magicIndexRepeated(v, 0, v.size());
}

int main()
{
    int len;
    cin >> len;
    vector<int> v(len);
    for(auto& i : v)
        cin >> i;
    cout << "magic index is " << magicIndex(v) << '\n';
    return 0;
}
