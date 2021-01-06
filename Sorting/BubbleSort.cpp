#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> iArray) {
  if(iArray.empty()) {
		return{};
	}
	bool isSorted = false;
	int aCounter = 0;
	while(! isSorted) {
		isSorted = true;
		for( int i = 0; i < iArray.size() - 1 - aCounter; i++) {
			if (iArray[i] > iArray[i + 1]) {
				swap(iArray[i], iArray[i + 1]);
				isSorted = false;
			}
		}
		aCounter++;
	}
	return iArray;  
}
