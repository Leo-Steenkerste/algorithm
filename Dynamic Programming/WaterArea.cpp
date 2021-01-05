#include <vector>
using namespace std;

// O(n) time | O(1) space - where n is the length of the input array
int waterArea(vector<int> iHeights) {
  if (iHeights.size() == 0) {
  	return 0;
  }

  auto aLeftIdx = 0;
  auto aRightIdx = iHeights.size() - 1;
  auto aLeftMax = iHeights[aLeftIdx];
  auto aRightMax = iHeights[aRightIdx];
  auto aSurfaceArea = 0;

  while (aLeftIdx < aRightIdx) {
  	if (iHeights[aLeftIdx] < iHeights[aRightIdx]) {
  		aLeftIdx++;
  		aLeftMax = max(aLeftMax, iHeights[aLeftIdx]);
  		aSurfaceArea += aLeftMax - iHeights[aLeftIdx];
  	}
  	else {
  		aRightIdx--;
  		aRightMax = max(aRightMax, iHeights[aRightIdx]);
  		aSurfaceArea += aRightMax - iHeights[aRightIdx];
  	}
  }

  return aSurfaceArea;
}