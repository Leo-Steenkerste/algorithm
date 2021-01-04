using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = NULL;
    right = NULL;
  }
};

void calculateBranchSums(BinaryTree *iNode, int iRunningSum, vector<int> &ioSums);

vector<int> branchSums(BinaryTree *root) {
  vector<int> aSums;
  calculateBranchSums(root, 0, aSums);
  return aSums;
}

void calculateBranchSums(BinaryTree *iNode, int iRunningSum, vector<int> &ioSums) {
  if(iNode == NULL) {
    return;
  }

  int newRunningSum = iRunningSum + iNode->value;
  if(iNode->left == NULL && iNode->right == NULL) {
    ioSums.push_back(newRunningSum);
    return;
  }
  
  calculateBranchSums(iNode->left, newRunningSum, ioSums);
  calculateBranchSums(iNode->right,newRunningSum, ioSums);
}
