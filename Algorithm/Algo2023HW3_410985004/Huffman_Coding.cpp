#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
#include "deque"
#include "string"
#include "iomanip"

using namespace std;

vector<string> code_of_symbol;
class Node
{
public:
    int val;
    int original_index;
    Node *left;
    Node *right;
    Node(int val, int index)
    {
        this->val = val;
        this->original_index = index;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int val, Node *left, Node *right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};
bool compare(Node *a, Node *b)
{
    return a->val < b->val;
}

// huffman_tree_decode
void huffman_tree_decode(Node *root, string code)
{
    Node *current = root;
    if (root->left == NULL && root->right == NULL)
    {
        code_of_symbol[root->original_index] = code;
    }
    if (root->left != NULL)
    {
        huffman_tree_decode(root->left, code + "0");
    }
    if (root->right != NULL)
    {
        huffman_tree_decode(root->right, code + "1");
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    code_of_symbol.resize(n);
    vector<int> symbol(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> symbol[i];
    }
    deque<Node *> forest;
    for (int i = 0; i < n; i++)
    {
        Node *node = new Node(symbol[i], i);
        forest.push_back(node);
    }
    while (forest.size() > 1)
    {
        sort(forest.begin(), forest.end(), compare);
        Node *left = forest.front();
        forest.pop_front();
        Node *right = forest.front();
        forest.pop_front();
        Node *parent = new Node(left->val + right->val, left, right);
        forest.push_back(parent);
    }
    Node *root = forest.front();
    cout << n << endl;
    huffman_tree_decode(root, "");

    // print
    cout << "|";
    for (int i = 0; i < n; i++)
    {
        cout << setw(5) << symbol[i] << "|";
    }
    cout << endl;
    cout << "|";
    for (int i = 0; i < n; i++)
    {
        cout << setw(5) << code_of_symbol[i] << "|";
    }
    cout << endl;
    return 0;
}
/*
Input
6
45 13 12 16 9 5
Output
6
0 101 100 111 1101 1100
*/