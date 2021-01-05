#include <vector>
using namespace std;

vector<char> buildSequence(vector<vector<int>> iLengths, string iStr);

vector<char> longestCommonSubsequence(string iStr1, string iStr2) {
  vector<vector<int>> aLengths(iStr2.length() + 1, vector<int>(iStr1.length() + 1, 0));
	for (int i = 1; i < iStr2.length() + 1; i++) {
		for (int j = 1; j < iStr1.length() + 1; j++) {
			if (iStr2[i - 1] == iStr1[j - 1]) {
				aLengths[i][j] = aLengths[i - 1][j - 1] + 1;
			}
			else {
				aLengths[i][j] = max(aLengths[i - 1][j], aLengths[i][j - 1]);
			}
		}
	}
  return buildSequence(aLengths, iStr1);
}

vector<char> buildSequence(vector<vector<int>> iLengths, string iStr) {
	vector<char> sequence;
	int i = iLengths.size() - 1;
	int j = iLengths[0].size() - 1;
	while (i != 0 && j != 0) {
		if (iLengths[i][j] == iLengths[i - 1][j]) {
			i--;
		}
		else if (iLengths[i][j] == iLengths[i][j - 1]) {
			j--;
		}
		else {
			sequence.insert(sequence.begin(), iStr[j - 1]);
			i--;
			j--;
		}
	}
	return sequence;
}