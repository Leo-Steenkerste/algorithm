// Two number sum
/*
Take an array containing int, and a target sum as input.
Return an array containing the two int that make the target number
Return an empty array if nothing was found
*/

// TODO : Add exception on input parameters
// TODO : Create template version

//Solution 1
// O(n^2) time | O(1) space
#include <vector>
using namespace std;

vector<int> twoNumberSum(const vector<int> iArray, const int iTargetSum) {
	for (int i = 0; i < iArray.size() - 1; ++i) {
		int aFirstNum = iArray[i];
		for (int j = 0; j < iArray.size(); ++j)	{
			int aSecondNum = iArray[j];
			if(aFirstNum + aSecondNum == iTargetSum) {
				return vector<int>{aFirstNum, aSecondNum};
			}
		}
	}
	return {};
}


//Solution 2
// O(n) time | O(n) space
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> twoNumberSum(const vector<int> iArray, const int iTargetSum) {
	unordered_set<int> aSetOfNums;
	for (int aNum : iArray) {
		int aPotentialMatch = iTargetSum - aNum;
		if(aSetOfNums.find(aPotentialMatch) != aSetOfNums.end()) {
			return vector<int> {aPotentialMatch, aNum};
		}
		else {
			aSetOfNums.insert(aNum);
		}
	}
	return {};
}


//Solution 3
//O(nlog(n)) | O(1) space

#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
	sort(array.begin(), array.end());
	int left = 0;
	int right = array.size() - 1;
	while (left < right) {
		int aResult = array[left] + array[right];
		if(aResult == targetSum) {
			return {array[left], array[right]};
		}
		else if(aResult > targetSum) {
			right--;
		}
		else if(aResult < targetSum){
			left++;
		}
	}
  return {};
}
