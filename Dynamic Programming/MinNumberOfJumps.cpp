#include <vector>
using namespace std;

// O(n) time | O(1) space
int minNumberOfJumps(vector<int> iArray) {
  if(iArray.size() == 1) {
  	return 0;
  }
  int aJumps = 0, aMaxReach = iArray[0], aSteps = iArray[0];
  for (int i = 1; i < iArray.size() - 1; i++) {
  	aMaxReach = max(aMaxReach, i + iArray[i]);
  	aSteps--;
  	if (aSteps == 0) {
  		aJumps++;
  		aSteps = aMaxReach - i;
  	}
  }

  return aJumps + 1;
}
