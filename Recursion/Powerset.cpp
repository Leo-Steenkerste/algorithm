#include <vector>
using namespace std;

vector<vector<int>> powerset(vector<int> array) {
  vector<vector<int>> subsets = {{}};
	for (int ele : array) {
		int length = subsets.size();
		for (int i = 0; i < length; i++) {
			vector<int> currentSubset = subsets[i];
			currentSubset.push_back(ele);
			subsets.push_back(currentSubset);
		}
	}
  return subsets;
}