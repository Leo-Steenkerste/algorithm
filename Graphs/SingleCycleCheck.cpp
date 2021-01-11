#include <vector>
using namespace std;

int getNextIdx(int currentIdx, vector<int> array);

// O(n) time | 0(1) space - where n is the length of the input array
bool hasSingleCycle(vector<int> array) {
  int numElementsVisited = 0, currentIdx = 0;

  while (numElementsVisited < array.size()) {
  	if (numElementsVisited > 0 && currentIdx == 0) {
  		return false;
  	}
  	numElementsVisited++;
  	currentIdx = getNextIdx(currentIdx, array);
  }
  return currentIdx == 0;
}

int getNextIdx(int currentIdx, vector<int> array) {
	int jump = array[currentIdx];
	int nextIdx = (currentIdx + jump) % (int) array.size();
	return nextIdx >= 0 ? nextIdx : nextIdx + array.size();
}