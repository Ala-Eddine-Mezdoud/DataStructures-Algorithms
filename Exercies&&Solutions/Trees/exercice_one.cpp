/*
Write efficient functions that take only a pointer to the root of a binary tree T and
compute:
- The number of nodes in T
- The number of leaves in T
- The number of full nodes in T (nodes which has non-empty left and right
    children)
- The depth of T
- The printing of the elements in T
What is the running time of your functions?
*/

#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to count the number of nodes
int countNodes(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to count the number of leaves
int countLeaves(TreeNode *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

// Function to count the number of full nodes
int countFullNodes(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int isFull = (root->left != NULL && root->right != NULL) ? 1 : 0;
    return isFull + countFullNodes(root->left) + countFullNodes(root->right);
}



// Main function to test
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Number of nodes: " << countNodes(root) << endl;
    cout << "Number of leaves: " << countLeaves(root) << endl;
    cout << "Number of full nodes: " << countFullNodes(root) << endl;
    cout << endl;

    return 0;
}
