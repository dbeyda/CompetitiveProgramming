#include <iostream>
#include <vector>
#include <queue>
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

bool commonAncestor(Node *tree, int p, int q, int& ancestor)
{
    if (!tree) return false;
    if (p == q && tree->value == p)
    {
        ancestor = tree->value;
        return true;
    }
    bool left = commonAncestor(tree->left, p, q, ancestor);
    bool right = commonAncestor(tree->right, p, q, ancestor);
    if(right && left)
    {
        ancestor = tree->value;
        return true;
    }
    if ((right || left) && (tree->value == p || tree->value == q))
    {
        ancestor = tree->value;
        return true;
    }
    if(tree->value == p || tree->value == q) return true;
    return left || right;

}

int main()
{
    vector<int> v;
    cout << "-- Type list number separated by space. Type \"end\" when finished:\n";
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
    cout << "Find common ancestor for which nodes?\n";
    int p, q;
    cin >> p >> q;
    int ancestor = -1;
    commonAncestor(tree, p, q, ancestor);
    cout << "Found common ancestor " << ancestor << ".\n";

    return 0;
}