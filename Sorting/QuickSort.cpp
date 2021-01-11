#include <vector>
using namespace std;

void quickSortHelper(vector<int> &iArray, int iStartIdx, int iEndIdx);

// Best : O(nlog(n)) time | O(log(n)) space
// Average : O(nlog(n)) time | O(log(n)) space
// Worst : O(n^2) time | O(log(n)) space
vector<int> quickSort(vector<int> iArray) {
  quickSortHelper(iArray, 0, iArray.size() - 1);
  return iArray;
}


void quickSortHelper(vector<int> &iArray, int iStartIdx, int iEndIdx) {
	if(iStartIdx >= iEndIdx) {
		return;
	}

	int pivotIdx = iStartIdx, leftIdx = iStartIdx + 1, rightIdx = iEndIdx;

	while (rightIdx >= leftIdx) {
		if (iArray.at(leftIdx) > iArray.at(pivotIdx) &&
			iArray.at(rightIdx) < iArray.at(pivotIdx)) {
			swap(iArray[leftIdx], iArray[rightIdx]);
		}
		if (iArray.at(leftIdx) <= iArray.at(pivotIdx)) {
			leftIdx += 1;
		}
		if (iArray.at(rightIdx) >= iArray.at(pivotIdx)) {
			rightIdx -= 1;
		}
	}
	swap(iArray[pivotIdx], iArray[rightIdx]);
	bool leftSubarrayIsSmaller = 
		rightIdx - 1 - iStartIdx < iEndIdx - (rightIdx + 1);
	if (leftSubarrayIsSmaller) {
		quickSortHelper(iArray, iStartIdx, rightIdx - 1);
		quickSortHelper(iArray, rightIdx + 1, iEndIdx);	
	}
	else {
		quickSortHelper(iArray, rightIdx + 1, iEndIdx);
		quickSortHelper(iArray, iStartIdx, rightIdx - 1);	
	}

}