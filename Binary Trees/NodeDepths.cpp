using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int iValue) {
    this->value = iValue;
    left = NULL;
    right = NULL;
  }
};

//Average case : when the tree is balanced
// O(n) time | O(h) space - when n is the number of node in 
// the Binary tree and h is the height of the Binary Tree
int nodeDepths(BinaryTree *iRoot, int iDepth = 0) {
  if (iRoot == NULL) {
    return 0;
  }
  return iDepth + nodeDepths(iRoot->left, iDepth + 1) + nodeDepths(iRoot->right, iDepth + 1);
}