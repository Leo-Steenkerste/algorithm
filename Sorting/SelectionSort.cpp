#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> iArray) {
  if (iArray.empty()) {
  	return {};
  }
  int startIdx = 0;
  while (startIdx < iArray.size() - 1) {
  	int smallestIdx = startIdx;
  	for (int i = startIdx + 1; i < iArray.size(); i++) {
  		if (iArray[smallestIdx] > iArray[i]) {
  			smallestIdx = i;
  		}
  	}
  	swap(iArray[startIdx], iArray[smallestIdx]);
  	startIdx++;
  }
  return iArray;
}
