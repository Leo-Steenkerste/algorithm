// TODO : Add Description
// TODO : Add exception on input parameters
// TODO : Create template version

#include <vector>
#include <unordered_map>

using namespace std;

vector<int> largestRange(vector<int> iArray) {
	vector<int> aBestRange = {};
	int aLongestLength = 0;
	unordered_map<int, bool> aNums = {};

	for (int aNum : iArray) {
		aNums[aNum] = true;
	}
	for(int aNum : iArray) {
		if(!aNums[aNum]) {
			continue;
		}
		aNums[aNum] = false;
		int aCurrentLength = 1, aLeft = aNum - 1, aRight = aNum + 1;
		while (aNums.find(aLeft) != aNums.end()) {
			aNums[aLeft] = false;
			aCurrentLength++;
			aLeft--;
		}
		while (aNums.find(aRight) != aNums.end()) {
			aNums[aRight] = false;
			aCurrentLength++;
			aRight++;
		}
		if (aCurrentLength > aLongestLength) {
			aLongestLength = aCurrentLength;
			aBestRange = {aLeft + 1, aRight - 1};
		}
	}
	return aBestRange;
}
