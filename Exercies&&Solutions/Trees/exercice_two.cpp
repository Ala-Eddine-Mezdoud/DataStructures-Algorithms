/*
Write a function to generate an N-node random binary search tree with distinct keys
1 through N.
What is the running time of your routine?
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
