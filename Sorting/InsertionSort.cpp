#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> iArray) {
  if (iArray.empty()) {
  	return {};
  }

  for (int i = 1; i < iArray.size(); i++) {
  	int j = i;
  	while (j > 0 && iArray[j] < iArray[j - 1]) {
  		swap(iArray[j], iArray[j - 1]);
  		j--;
  	}
  }

  return iArray;
}
