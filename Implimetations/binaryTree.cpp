#include <iostream>
using namespace std;

template <typename Object>
struct binaryTree
{
    Object data;
    binaryTree *left;
    binaryTree *right;
    binaryTree(Object value) : data(value), left(nullptr), right(nullptr) {}
};
