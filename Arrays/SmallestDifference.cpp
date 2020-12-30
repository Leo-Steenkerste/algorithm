
// TODO : Add Description
// TODO : Add exception on input parameters
// TODO : Create template version


#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// O(nlog(n) + mlog(m) time | 0(1) space

vector<int> smallestDifference(vector<int> iArrayOne, vector<int> iArrayTwo) {
  sort(iArrayOne.begin(), iArrayOne.end());
  sort(iArrayTwo.begin(), iArrayTwo.end());
  int aIndexOne = 0, aIndexTwo = 0, aSmallest = INT_MAX, aCurrent = INT_MAX;
  vector<int> aSmallestPair;


  while (aIndexOne < iArrayOne.size() && aIndexTwo < iArrayTwo.size()) {
  	int aFirstNum = iArrayOne[aIndexOne], aSecondNum = iArrayTwo[aIndexTwo];
  	
  	if (aFirstNum < aSecondNum) {
  		aCurrent = aSecondNum - aFirstNum;
  		aIndexOne++;
  	}
  	else if (aSecondNum < aFirstNum) {
  		aCurrent = aFirstNum - aSecondNum;
  		aIndexTwo++;
  	}
  	else 
  	{
  		return vector<int>{aFirstNum, aSecondNum};
  	}
  	if (aSmallest > aCurrent) 
  	{
  		aSmallest = aCurrent;
  		aSmallestPair = {aFirstNum, aSecondNum};
  	}
  }	
  return aSmallestPair;
}