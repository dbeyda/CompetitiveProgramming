#include <bits/stdc++.h>
#include <iostream>
#include <functional>

using namespace std;

// Segment Tree, the Recursive Way

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
            cout << "-- found a leaf! writing " << v[left] << " to pos " << treeIdx << endl;
            tree[treeIdx] = v[left];
        }
        else
        {
            int middle = (left + right)/2;
            build(v, left, middle, 2*treeIdx + 1);
            build(v, middle+1, right, 2*treeIdx + 2);
            // combining both children; combine function can be changed
            cout << "-- combining " << tree[treeIdx*2+1] << " and " << tree[treeIdx*2+2] << " to pos " << treeIdx << endl;
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

int main()
{
    cout << "start" << endl;
    vector<int> v = {1, 2, 3, 4, 5, 6};
    int n = v.size();
    cout << "vector filled: ";
    for(auto& i : v)
        cout << i << " ";
    cout << endl;

    // testing build tree
    cout << "building tree..." << endl;
    SegTree<int> t(v, -1, [](int first, int second){return first + second;});
    cout << "building finished: ";
    for(int i=0; i<t.tree.size(); i++)
        cout << t.tree[i] << " ";
    cout << endl;

    // testing query
    cout << "\nSum of all: " << t.queryAll() << endl;
    cout << "Sum of [3-5]: " << t.query(3, 5) << endl;

    // testing update
    cout << "\nUpdating vector[0] to 2...\n";
    t.update(0, 2);
    cout << "Sum of all: " << t.query(0, n-1) << endl;
    cout << "Updating vector[5] to 10...\n";
    t.update(5, 10);
    cout << "Sum of all: " << t.query(0, n-1) << endl;

    cout << "\nFinal vector: ";
    for(int i=0; i<t.tree.size(); i++)
        cout << t.tree[i] << " ";
    cout << endl;

    return 0;
}