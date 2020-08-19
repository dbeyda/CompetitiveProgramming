/*
Minimal Tree: Given a sorted (increasing order) array with unique integer elements, write an
algorithm to create a binary search tree with minimal height.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#define COUNT 15
using namespace std;

class Node {
public:
    int value;
    Node *left = nullptr;
    Node *right = nullptr;
};

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->value<<"\n";

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(Node *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

Node *insertBST(Node *root, int i)
{
    if(!root)
        return new Node({i});
    if (i <= root->value)
        root->left = insertBST(root->left, i);
    else
        root->right = insertBST(root->right, i);
    return root;
}

Node *buildTree(vector<int> v, int start, int end)
{
    if (!v.size()) return nullptr;
    if (start > end) return nullptr;
    int mid = (start + end) / 2;
    Node *n = new Node({v[mid]});
    n->left = buildTree(v, start, mid-1);
    n->right = buildTree(v, mid+1, end);
    return n;
}


int getPathsWithSum(int target, Node *tree, unordered_map<int, int>& hashtable, int runningSum)
{
    if (!tree) return 0;
    runningSum += tree->value;
    hashtable[runningSum]++;
    int total = hashtable[runningSum-target];
    total += getPathsWithSum(target, tree->left, hashtable, runningSum);
    total += getPathsWithSum(target, tree->right, hashtable, runningSum);
    hashtable[runningSum]--;
    return total;
}

int main()
{
    vector<int> v;
    cout << "-- Type list number separated by space. We will build a binary search tree.\nType \"end\" when finished:\n";
    string s;
    cin >> s;
    while(s != "end")
    {
        v.push_back(stoi(s));
        cin >> s;
    }

    cout << "-- Ok. Got the following:\n";
    for(auto& i : v)
        cout << i << " ";
    cout << '\n';
    cout << "Building tree...\n";
    Node * tree = buildTree(v, 0, v.size()-1);
    cout << "Build tree:\n";

    print2D(tree);

    cout << "Search for paths that sum: ";
    int target;
    cin >> target;
    unordered_map<int, int> hashtable;
    hashtable[0] = 1;
    int total = getPathsWithSum(target, tree, hashtable, 0);
    cout << "Found " << total << " paths with sum " << target << ".\n";
    return 0;
}