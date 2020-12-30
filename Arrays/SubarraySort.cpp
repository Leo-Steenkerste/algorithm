// TODO : Add Description
// TODO : Add exception on input parameters
// TODO : Create template version

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool isOutOfOrder(int i, int num, vector<int> iArray);

// O(n) time | O(1) space
vector<int> subarraySort(vector<int> iArray) {
	int aMinOutOfOrder = INT_MAX, aMaxOutOfOrder = INT_MIN;
	
	for (int i = 0; i < iArray.size(); i++) {
		int aNum = iArray[i];
		if (isOutOfOrder(i, aNum, iArray)) {
			aMinOutOfOrder = min(aMinOutOfOrder, aNum);
			aMaxOutOfOrder = max(aMaxOutOfOrder, aNum);
		}
	}
	
	if (aMinOutOfOrder == INT_MAX) {
		return vector<int>{-1, -1};
	}

	int aSubarrayLeftIdx = 0;
	while (aMinOutOfOrder >= iArray[aSubarrayLeftIdx]) {
		aSubarrayLeftIdx++;
	}
	int aSubarrayRightIdx = iArray.size() - 1;
	while (aMaxOutOfOrder <= iArray[aSubarrayRightIdx]) {
		aSubarrayRightIdx--;
	}
	return vector<int>{aSubarrayLeftIdx, aSubarrayRightIdx};
}

bool isOutOfOrder(int i, int iNum, vector<int> iArray) {
	if(i == 0) {
		return iNum > iArray[i + 1];
	}
	if (i == iArray.size() - 1) {
		return iNum < iArray[i - 1];
	}
	return iNum > iArray[i + 1] || iNum < iArray[i - 1];
}