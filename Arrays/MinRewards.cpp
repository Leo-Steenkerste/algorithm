// TODO : Add Description
// TODO : Add exception on input parameters
// TODO : Create template version

#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

// O(n) time | O(n) space - where n is the length of the input array
int minRewards(vector<int> iScores) {
	vector<int> iRewards = vector<int>(iScores.size(), 1);
	for (int i = 1; i < iScores.size(); i++) {
		if (iScores[i] > iScores[i - 1]) {
			iRewards[i] = iRewards[i - 1] + 1;
		}
	}

	for (int i = iScores.size() - 2; i >= 0; i--) {
		if (iScores[i] > iScores[i + 1]) {
			iRewards[i] = max(iRewards[i], iRewards[i + 1] + 1);
		}
	}
	
	return accumulate(iRewards.begin(), iRewards.end(), 0);
}
