#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

template <class T>
class SegTree
{
public:
    int maxRightLimit;
    vector<T> tree;
    std::function<T(T, T)> combineFunc;

    SegTree(vector<T>& v, T defaultValue, std::function<T(T, T)> func)
    {
        combineFunc = func;
        maxRightLimit = v.size()-1;
        tree.assign(4*v.size(), defaultValue);
        build(v, 0, maxRightLimit);
    }

    void build(vector<T>& v, int left, int right, int treeIdx=0)
    {
        if(left == right)
        {
            // cout << "-- found a leaf! writing " << v[left] << " to pos " << treeIdx << endl;
            tree[treeIdx] = v[left];
        }
        else
        {
            int middle = (left + right)/2;
            build(v, left, middle, 2*treeIdx + 1);
            build(v, middle+1, right, 2*treeIdx + 2);
            // combining both children; combine function can be changed
            // cout << "-- combining " << tree[treeIdx*2+1] << " and " << tree[treeIdx*2+2] << " to pos " << treeIdx << endl;
            tree[treeIdx] = combineFunc(tree[treeIdx*2+1], tree[treeIdx*2+2]);
        }
    }

    T queryRecursive(int qLeft, int qRight, int left, int right, int treeIdx=0)
    {
        if(qLeft == left && qRight == right)
            return tree[treeIdx];
        int middle = (left + right) / 2;
        if (qRight <= middle)
            return queryRecursive(qLeft, qRight, left, middle, treeIdx*2+1);
        if (qLeft > middle)
            return queryRecursive(qLeft, qRight, middle+1, right, treeIdx*2+2);

        T leftValue = queryRecursive(qLeft, middle, left, middle, treeIdx*2+1);
        T rightValue = queryRecursive(middle+1, qRight, middle+1, right, treeIdx*2+2);
        // COMBINE function can be changed
        return combineFunc(leftValue, rightValue);
    }

    T query(int qLeft, int qRight)
    {
        return queryRecursive(qLeft, qRight, 0, maxRightLimit, 0);
    }

    T queryAll()
    {
        return queryRecursive(0, maxRightLimit, 0, maxRightLimit, 0);
    }


    void updateRecursive(int originalIdxUpdate, T newValue, int left, int right, int treeIdx=0)
    {
        if(left == right && left == originalIdxUpdate)
        {
            tree[treeIdx] = newValue;
            return;
        }

        int middle = (left + right)/2;
        if (originalIdxUpdate <= middle)
            updateRecursive(originalIdxUpdate, newValue, left, middle, treeIdx*2+1);
        else
            updateRecursive(originalIdxUpdate, newValue, middle+1, right, treeIdx*2+2);

        // combining both children; combine function can be changed
        tree[treeIdx] = combineFunc(tree[treeIdx*2+1], tree[treeIdx*2+2]);
    }

    void update(int originalIdxUpdate, T newValue)
    {
        updateRecursive(originalIdxUpdate, newValue, 0, maxRightLimit);
    }
};

// ------- Solution code

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> lastSeen(n+1, -1);
    vector<int> colors(n, 0);

    // read colors
    for(auto& c : colors)
        cin >> c;
    // read queries
    list<vector<int>> queries;
    for(int i=0; i<q; i++)
    {
        int x, y;
        cin >> x >> y;
        queries.push_back(vector<int> ({x, y, i}));
    }
    queries.sort([] (vector<int>& a, vector<int>& b) { return a[1] < b[1]; });

    // process queries
    vector<int> increment(n, 0);
    SegTree<int> t(increment, 0, [](int a, int b) {return a + b;});
    list<vector<int>> answer;
    for(int i=0; i<n; i++)
    {
        // update increments
        int c = colors[i];
        if (lastSeen[c] >= 0)
        {
            increment[lastSeen[c]] = 0;
            t.update(lastSeen[c], 0);
        }
        increment[i] = 1;
        t.update(i, 1);
        lastSeen[c] = i;

        // process queries
        while(!queries.empty() && queries.front()[1] - 1 == i)
        {
            vector<int> q = queries.front();
            queries.pop_front();
            int ans = t.query(q[0]-1, q[1]-1);
            answer.push_back(vector<int>({q[2], ans}));
        }
    }

    answer.sort([](vector<int>& a, vector<int>& b) { return a[0] < b[0];});
    for(auto& ans : answer)
        cout << ans[1] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nCases = 1;
    // cin >> nCases;

    while(nCases--)
        solve();

    return 0;
}
