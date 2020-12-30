
#include<cmath>
#include <float.h>

using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

int findClosestValueInBst(BST *iTree, int iTarget);
int findClosestValueInBstHelper(BST *iTree, int iTarget, int oClosest);

// Average : O(log(n)) time | O(log(n)) space
// Worst: O(n) time | O(n) space
int findClosestValueInBst(BST *iTree, int iTarget) {
	return findClosestValueInBstHelper(iTree, iTarget, iTree->value);
}

int findClosestValueInBstHelper(BST *iTree, int iTarget, int oClosest) {
	if (abs(iTarget - oClosest) > abs(iTarget - iTree->value)) {
		oClosest = iTree->value;
	}
	if (iTarget < iTree->value && iTree->left != NULL) {
		return findClosestValueInBstHelper(iTree->left, iTarget, oClosest);
	}
	else if (iTarget > iTree->value && iTree->right != NULL) {
		return findClosestValueInBstHelper(iTree->right, iTarget, oClosest);
	}
	else {
		return oClosest;
	}
}