#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};


//First Solution with algo : O(n) time | O(n) space
// void invertBinaryTree(BinaryTree *tree) {
//   deque<BinaryTree *> queue;
//   queue.push_back(tree);
//   while (queue.size() > 0) {
//   	BinaryTree *current = queue.front();
//   	queue.pop_front();
//   	if (current == NULL) {
//   		continue;
//   	}
//   	swap(current->left, current->right);
//   	queue.push_back(current->left);
//   	queue.push_back(current->right);
//   }
// }


//Second Solution with algo : O(n) time | O(d) space
void invertBinaryTree(BinaryTree *tree) {
  if(tree == NULL) {
  	return;
  }
  swap(tree->left, tree->right);
  invertBinaryTree(tree->left);
  invertBinaryTree(tree->right);
}