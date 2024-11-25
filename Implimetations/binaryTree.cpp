#include <iostream>
using namespace std;

template <typename Object>
class binaryTree
{
private:
    Object data;
    binaryTree *left;
    binaryTree *right;

public:
    binaryTree(Object value) : data(value), left(nullptr), right(nullptr) {}
};
