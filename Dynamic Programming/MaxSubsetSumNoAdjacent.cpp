#include <vector>
using namespace std;

// O(n) time | 0(1) space
int maxSubsetSumNoAdjacent(vector<int> iArray) {
  if (iArray.size() == 0) {
  	return 0;
  }
  else if (iArray.size() == 1) {
  	return iArray[0];
  }
  int aSecond = iArray[0];
  int aFirst = max(iArray[0], iArray[1]);
  for (int i = 2; i < iArray.size(); i++) {
  	int current = max(aFirst, aSecond + iArray[i]);
  	aSecond = aFirst;
  	aFirst = current;
  }
  return aFirst;
}

