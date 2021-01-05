#include <vector>
using namespace std;

vector<vector<int>> getKnapsackItems(vector<vector<int>> iKnapsackValues, vector<vector<int>> iItems, int iWeight);

vector<vector<int>> knapsackProblem(vector<vector<int>> iItems, int iCapacity) {
	vector<vector<int>> aKnapsackValues(iItems.size() + 1, vector<int>(iCapacity + 1, 0));
	for (int i = 1; i < iItems.size() + 1; i++) {
		int currentWeight = iItems[i - 1][1];
		int currentValue = iItems[i - 1][0];
		for(int c = 0; c < iCapacity + 1; c++) {
			if(currentWeight > c) {
				aKnapsackValues[i][c] = aKnapsackValues[i - 1][c];
			}
			else {
				aKnapsackValues[i][c] = max(aKnapsackValues[i - 1][c], aKnapsackValues[i - 1][c - currentWeight] + currentValue);
			}
		}
	}
	return getKnapsackItems(aKnapsackValues, iItems, aKnapsackValues[iItems.size()][iCapacity]);
}

vector<vector<int>> getKnapsackItems(vector<vector<int>> iKnapsackValues, vector<vector<int>> iItems, int iWeight) {
	vector<vector<int>> aSolution = {{}, {}};
	int i = iKnapsackValues.size() - 1;
	int c = iKnapsackValues[0].size() - 1;
	while (i > 0) {
		if (iKnapsackValues[i][c] == iKnapsackValues[i - 1][c]) {
			i--;
		}
		else {
			aSolution[1].insert(aSolution[1].begin(), i - 1);
			c -= iItems[i - 1][1];
			i--;
		}
		if (c == 0) {
			break;
		}
	}
	aSolution[0].push_back(iWeight);
	return aSolution;
}
