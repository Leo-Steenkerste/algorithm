#include <vector>
using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
  int value;
  BinaryTree *left = NULL;
  BinaryTree *right = NULL;

  BinaryTree(int value);
};

vector<BinaryTree *> flattenTree(BinaryTree *node);
void connectNodes(BinaryTree *left, BinaryTree *right);

BinaryTree *flattenBinaryTree(BinaryTree *root) {
  BinaryTree *leftMost = flattenTree(root)[0];
  return leftMost;
}

vector<BinaryTree *> flattenTree(BinaryTree *node) {
	BinaryTree *leftMost;
	BinaryTree *rightMost;

	if(node->left == NULL) {
		leftMost = node;
	}
	else {
		vector<BinaryTree *> leftAndRightMostNodes = flattenTree(node->left);
		connectNodes(leftAndRightMostNodes[1], node);
		leftMost = leftAndRightMostNodes[0];
	}

	if(node->right == NULL) {
		rightMost = node;
	}
	else {
		vector<BinaryTree *> leftAndRightMostNodes = flattenTree(node->right);
		connectNodes(node, leftAndRightMostNodes[0]);
		rightMost = leftAndRightMostNodes[1];
	}

	return {leftMost, rightMost};
}

void connectNodes(BinaryTree *left, BinaryTree *right) {
	left->right = right;
	right->left = left;
}