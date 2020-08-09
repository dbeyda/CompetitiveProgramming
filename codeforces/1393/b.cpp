#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <functional>


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
            tree[treeIdx] = v[left];
        else
        {
            int middle = (left + right)/2;
            build(v, left, middle, 2*treeIdx + 1);
            build(v, middle+1, right, 2*treeIdx + 2);
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

        tree[treeIdx] = combineFunc(tree[treeIdx*2+1], tree[treeIdx*2+2]);
    }

    void update(int originalIdxUpdate, T newValue)
    {
        updateRecursive(originalIdxUpdate, newValue, 0, maxRightLimit);
    }
};

// ----------- Solution code

struct Node{
    int value = 0;
    int squarePairs = 0;
    int totalPairs = 0;
};


void solve()
{
    int n;
    cin >> n;
    vector<Node> v((size_t) 1e5+15, {0, 0, 0});

    for(int i=0; i<n; i++)
    {
        int x; cin >> x;
        v[x].value++;
    }

    // segTree combine func
    auto combineFunc = [](Node first, Node second)
        {
            int squarePairs, totalPairs;
            totalPairs = squarePairs = 0;
            if(first.value>=0 && second.value>=0)
            {
                // both leaves
                totalPairs = first.value/2 + second.value/2;
                squarePairs = max(first.value/2, second.value/2);
            }
            else if (first.value>=0)
            {
                // one leaf
                totalPairs = second.totalPairs + first.value/2;
                squarePairs = max(second.squarePairs, first.value/2);
            }
            else if (second.value>=0)
            {
                // one leaf
                totalPairs = first.totalPairs + second.value/2;
                squarePairs = max(first.squarePairs, second.value/2);
            }
            else
            {
                // both internal nodes
                totalPairs = first.totalPairs + second.totalPairs;
                squarePairs = max(first.squarePairs, second.squarePairs);
            }
            // Node.value = -1 is the identifier for an internal node
            return Node{
                -1,
                squarePairs,
                totalPairs
            };
        };
    SegTree<Node> t(v, {0, 0, 0}, combineFunc);

    // Process Operations
    int q; cin >> q;
    char signal;
    int trunkSize;
    while(q--)
    {
        cin >> signal >> trunkSize;
        if (signal == '-')
            v[trunkSize].value--;
        else
            v[trunkSize].value++;
        t.update(trunkSize, v[trunkSize]);

        Node result = t.queryAll();
        if (result.squarePairs >= 2 && result.totalPairs >= 4)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
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
