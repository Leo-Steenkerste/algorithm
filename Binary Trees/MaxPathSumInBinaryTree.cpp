#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
};

vector<int> findMaxSum(BinaryTree *iTree);

// O(n) time | O(log(n)) space
int maxPathSum(BinaryTree iTree) {
  vector<int> maxSumArray = findMaxSum(&iTree);
  return maxSumArray[1];
}

vector<int> findMaxSum(BinaryTree *iTree) {
	if (iTree == NULL) {
		return vector<int>{0, INT_MIN};
	}

	vector<int> leftMaxSumArray = findMaxSum(iTree->left);
	int leftMaxSumAsBranch = leftMaxSumArray[0];
	int leftMaxPathSum = leftMaxSumArray[1];

	vector<int> rightMaxSumArray = findMaxSum(iTree->right);
	int rightMaxSumAsBranch = rightMaxSumArray[0];
	int rightMaxPathSum = rightMaxSumArray[1];

	int maxChildSumAsBranch = max(leftMaxSumAsBranch, rightMaxSumAsBranch);
	int maxSumAsBranch = max(maxChildSumAsBranch + iTree->value, iTree->value);
	int maxSumAsRootNode = max(leftMaxSumAsBranch + iTree->value + rightMaxSumAsBranch, maxSumAsBranch);
	int maxPathSum = max(leftMaxPathSum, max(rightMaxPathSum, maxSumAsRootNode));

	return vector<int>{maxSumAsBranch, maxPathSum};

}