
#include <climits>
using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

bool validateBst(BST *iTree);
bool validateBstHelper(BST *iTree, int iMinValue, int iMaxValue); 

// O(n) time | o(d) space
bool validateBst(BST *iTree) {
  return validateBstHelper(iTree, INT_MIN, INT_MAX);
}

bool validateBstHelper(BST *iTree, int iMinValue, int iMaxValue) {
	if(iTree->value < iMinValue || iTree->value >= iMaxValue) {
		return false;
	}
	if(iTree->left != NULL && !validateBstHelper(iTree->left, iMinValue, iTree->value)) {
		return false;
	}
	if(iTree->right != NULL && !validateBstHelper(iTree->right, iTree->value, iMaxValue)) {
		return false;
	}
	return true;
}

