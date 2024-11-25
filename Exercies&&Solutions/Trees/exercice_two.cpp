/*
Write a function to generate an N-node random binary search tree with distinct keys
1 through N.
What is the running time of your routine?
*/
#include <iostream>
#include <vector>
#include <cstdlib> // for rand and srand
#include <ctime>   // for time
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to insert a value into the BST
TreeNode *insert(TreeNode *root, int val)
{
    if (root == NULL)
        return new TreeNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Function to generate a random BST with keys 1 through N
TreeNode *generateRandomBST(int N)
{
    TreeNode *root = NULL;
    vector<int> values;

    // Create a list of numbers from 1 to N
    for (int i = 1; i <= N; ++i)
        values.push_back(i);

    // Shuffle the list randomly
    srand(time(0)); // Seed the random number generator
    for (int i = 0; i < N; ++i)
    {
        int j = rand() % (N - i) + i; // Generate a random index
        swap(values[i], values[j]);
    }

    // Insert each shuffled value into the BST
    for (int val : values)
        root = insert(root, val);

    return root;
}

// Function to print the BST in inorder traversal
void inorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main()
{
    int N;
    cout << "Enter the number of nodes (N): ";
    cin >> N;

    // Generate the random BST
    TreeNode *root = generateRandomBST(N);

    // Print the inorder traversal
    cout << "Inorder traversal of the generated BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
