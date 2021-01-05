using namespace std;

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

int allKindsOfNodeDepthsHelper(BinaryTree *root, int depth);



int allKindsOfNodeDepths(BinaryTree *root) {
  return allKindsOfNodeDepthsHelper(root, 0);
}

int allKindsOfNodeDepthsHelper(BinaryTree *root, int depth) {
  if(root == NULL) {
    return 0;
  }

  //formula to calculate 1 + 2 + 3 + .... + depth - 1 + depth
  auto depthSum = (depth * (depth + 1)) / 2;
  return depthSum + allKindsOfNodeDepthsHelper(root->left, depth + 1) + allKindsOfNodeDepthsHelper(root->right, depth + 1);
}