#include <iostream>
using namespace std;

template <typename Object>
struct binarynode
{
    Object data;
    binarynode *left;
    binarynode *right;
    binarynode(Object value = NULL) : data(value), left(nullptr), right(nullptr) {}
};

template <typename Object>
class binaryTree
{
private:
    binarynode<Object> *root;

public:
    binaryTree(Object value)
    {
        root->data = value;
    };
    int countNodes()
    {
        if (root = NULL)
        {
            return 0;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
