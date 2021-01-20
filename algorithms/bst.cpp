#include <bits/stdc++.h>
#include <iostream>
#include <functional>

using namespace std;

// Segment Tree, the Recursive Way

template <class T>
class Bst
{
public:
    struct Node
    {
        T value;
        Node *left = nullptr;
        Node *right = nullptr;
    };
    Node *head = nullptr;

private:
    int _size = 0;


public:
    /**
     * @param v ordered vector of values to insert in the tree
     */
    Bst(vector<T>& v)
    {
        head = insertOrderedValues(v, 0, v.size()-1);
    }

    Node *insertOrderedValues(vector<T> &v, int start, int end)
    {
        if (start > end) return nullptr;
        int mid = (start+end)/2;
        auto& value = v[mid];
        Node *node = new Node({value});
        ++_size;
        node->left = insertOrderedValues(v, start, mid-1);
        node->right = insertOrderedValues(v, mid+1, end);
        return node;
    }

    int size() { return _size; };

    bool find(T value)
    {
        return _find(value, head);
    }

private:
    bool _find(T value, Node* searchHead = nullptr)
    {
        if (!searchHead) return false;
        if(value < searchHead->value) return _find(value, searchHead->left);
        if(value > searchHead->value) return _find(value, searchHead->right);
        // case equal
        return true;
    }
};

int main()
{
    cout << "start" << endl;
    vector<int> v = {1, 2, 3, 4, 5, 6, 25, 28};
    int n = v.size();
    cout << "vector filled: ";
    for(auto& i : v)
        cout << i << " ";
    cout << endl;

    // testing build tree
    cout << "building bst..." << endl;
    Bst<int> bst(v);
    cout << "building finished: ";
    cout << "tree size: " << bst.size() << endl;
    cout << endl;

    // testing query
    cout << "\nTesting truthy queries:\n";
    cout << "Quering for 2: " << bst.find(2) << endl;
    cout << "Quering for 1: " << bst.find(1) << endl;
    cout << "Quering for 3: " << bst.find(3) << endl;
    cout << "Quering for 28: " << bst.find(28) << endl;
    cout << "Quering for 25: " << bst.find(25) << endl;

    cout << "\nTesting falsy queries:\n";
    cout << "Quering for -2: " << bst.find(-2) << endl;
    cout << "Quering for 23: " << bst.find(23) << endl;
    cout << "Quering for 29: " << bst.find(29) << endl;

    return 0;
}