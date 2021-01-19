#include <vector>
using namespace std;


// O(log(n)) time | O(1) space - where n is the length of the input array
int indexEqualsValue(vector<int> array) {
  int leftIndex = 0;
  int rightIndex = array.size() - 1;

  while (leftIndex <= rightIndex) {
  	int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
  	int middleValue = array[middleIndex];

  	if (middleValue < middleIndex) {
  		leftIndex = middleIndex + 1;
  	}
  	else if (middleValue == middleIndex && middleIndex == 0) {
  		return middleIndex;
  	}
  	else if (middleValue == middleIndex && array[middleIndex - 1] < middleIndex - 1) {
  		return middleIndex;
  	}
  	else {
  		rightIndex = middleIndex - 1;
  	}
  }
  return -1; 
}
