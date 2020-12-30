#include <vector>
using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
};

// O(n) time | O(n) space
void inOrderTraverse(BST *iTree, vector<int> &iArray) {
  if(iTree != NULL) {
  	inOrderTraverse(iTree->left, iArray);
  	iArray.push_back(iTree->value);
  	inOrderTraverse(iTree->right, iArray);
  }
}

// O(n) time | O(n) space
void preOrderTraverse(BST *iTree, vector<int> &iArray) {
  if(iTree != NULL) {
  	iArray.push_back(iTree->value);
  	preOrderTraverse(iTree->left, iArray);
  	preOrderTraverse(iTree->right, iArray);
  }
}

// O(n) time | O(n) space
void postOrderTraverse(BST *iTree, vector<int> &iArray) {
	if(iTree != NULL) {
		postOrderTraverse(iTree->left, iArray);
		postOrderTraverse(iTree->right, iArray);
		iArray.push_back(iTree->value);
	}
}
