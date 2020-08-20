#include <iostream>
#include <vector>
#include <queue>
#include <list>
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

Node *buildBST(list<int>& v)
{
    Node * bst = nullptr;
    for(auto& i : v)
        bst = insertBST(bst, i);
    return bst;
}

void weave(list<int>& left, list<int>& right, vector<list<int>>& weaved, list<int>& prefix)
{
    if (!left.size())
    {
        list<int> final = prefix;
        final.insert(final.end(), right.begin(), right.end());
        weaved.push_back(final);
    }
    else if (!right.size())
    {
        list<int> final = prefix;
        final.insert(final.end(), left.begin(), left.end());
        weaved.push_back(final);
    }
    else
    {
        // left call
        prefix.push_back(left.front());
        left.pop_front();
        weave(left, right, weaved, prefix);
        left.push_front(prefix.back());
        prefix.pop_back();
        // right call
        prefix.push_back(right.front());
        right.pop_front();
        weave(left, right, weaved, prefix);
        right.push_front(prefix.back());
        prefix.pop_back();
    }

}

vector<list<int>> getAllArrays(Node * root)
{
    vector<list<int>> result;
    if (!root)
    {
        result.push_back(list<int>());
        return result;
    }
    vector<list<int>> leftArrays = getAllArrays(root->left);
    vector<list<int>> rightArrays = getAllArrays(root->right);

    list<int> prefix({root->value});
    for(auto& leftA : leftArrays)
        for(auto& rightA : rightArrays)
        {
            vector<list<int>> weaved;
            weave(leftA, rightA, weaved, prefix);
            result.insert(result.end(), weaved.begin(), weaved.end());
        }
    return result;
}

int main()
{
    list<int> v;
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
    Node * tree = buildBST(v);
    cout << "Build tree:\n";

    print2D(tree);
    cout << "Weaving and stuff...\n";
    vector<list<int>> all = getAllArrays(tree);
    cout << "All possible arrays that could generate such tree:\n";
    for(auto& arr : all)
    {
        for(auto& i : arr)
            cout << i << " ";
        cout << '\n';
    }

    return 0;
}