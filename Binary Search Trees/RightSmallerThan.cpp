
using namespace std;

class SpecialBST {
public: 
	int value;
	int leftSubtreeSize;
	SpecialBST *left;
	SpecialBST *right;

	SpecialBST(int value) {
		this->value = value;
		leftSubtreeSize = 0;
		left = NULL;
		right = NULL;
	}

	void insert(int value, int idx, vector<int> &rightSmallerCounts, int numSmallerAtInsertTime = 0) { 
		if (value < this->value) { 
			leftSubtreeSize++; 
			if (left == NULL) { 
				left = new SpecialBST(value); 
				rightSmallerCounts[idx] = numSmallerAtInsertTime; 
			} 
			else { 
				left->insert(value, idx, rightSmallerCounts, numSmallerAtInsertTime); 
			}
		}
		else { 
			numSmallerAtInsertTime += leftSubtreeSize; 
			if (value > this->value) {
				numSmallerAtInsertTime++; 
			}
			if (right == NULL) { 
				right = new SpecialBST(value); 
				rightSmallerCounts[idx] = numSmallerAtInsertTime; 
			}
			else { 
				right->insert(value, idx, rightSmallerCounts, numSmallerAtInsertTime); 
			}
		} 
	}
};

// Average case: when the created BST is balanced 
// 0(nlog(n)) time 1 0(n) space - where n is the length of the array 
// ---
// Worst case: when the created BST is like a linked list 
// 0(nA2) time 1 0(n) space 

vector<int> rightSmallerThan(vector<int> array) { 
	if (array.size() == 0)
		return {}; 
	vector<int> rightSmallerCounts = array; 
	int lastIdx = array.size() - 1; 
	SpecialBST *bst = new SpecialBST(array[lastIdx]);
	rightSmallerCounts[lastIdx] = 0; 
	for (int i = array.size() - 2; i >= 0; i--) { 
		bst->insert(array[i], i, rightSmallerCounts); 
	} 
	return rightSmallerCounts; 
} 