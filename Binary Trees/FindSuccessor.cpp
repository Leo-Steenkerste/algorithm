using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;
  BinaryTree *parent = nullptr;

  BinaryTree(int iValue) { this->value = iValue; }
};

BinaryTree * getLeftmostChild(BinaryTree *iNode);
BinaryTree * getRightmostChild(BinaryTree *iNode);

BinaryTree *findSuccessor(BinaryTree *iTree, BinaryTree *iNode) {
	if(iNode->right != nullptr) {
		return getLeftmostChild(iNode->right);
	}
	return getRightmostChild(iNode);
}


BinaryTree * getLeftmostChild(BinaryTree *iNode) {
	auto currentNode = iNode;
	while (currentNode->left != nullptr) {
		currentNode = currentNode->left;
	}
	return currentNode;
}


BinaryTree * getRightmostChild(BinaryTree *iNode) {
	auto currentNode = iNode;
	while (currentNode->parent != nullptr && currentNode->parent->right == currentNode) {
		currentNode = currentNode->parent;
	}

	return currentNode->parent;
}
