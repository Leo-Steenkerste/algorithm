#include <vector>
#include <algorithm>
using namespace std;

// O(n) time | O(1) space - where n is the length of the array
vector<int> threeNumberSort(vector<int> iArray, vector<int> iOrder) {
  int firstValue = iOrder[0];
  int secondValue = iOrder[1];

  int firstIdx = 0, secondIdx = 0, thirdIdx = iArray.size() - 1;

  while (secondIdx <= thirdIdx) {
    int value = iArray[secondIdx];

    if(value == firstValue) {
      swap(iArray[firstIdx], iArray[secondIdx]);
      firstIdx += 1;
      secondIdx += 1;
  }
  else if (value == secondValue) {
    secondIdx += 1;
  }
  else {
    swap(iArray[secondIdx], iArray[thirdIdx]);
    thirdIdx--;
  }
  } 

  return iArray;
}
