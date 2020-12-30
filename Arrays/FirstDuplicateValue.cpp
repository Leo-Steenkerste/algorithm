// TODO : Add Description
// TODO : Add exception on input parameters
// TODO : Create template version

#include <vector>
#include <algorithm>
using namespace std;

// O(n) time | O(1) space - where n is the lenght of the input array
int firstDuplicateValue(vector<int> array) {
	for (int value : array) {
		int absValue = abs(value);
		if(array[absValue - 1] < 0) {
			return absValue;
		}
		array[absValue - 1] *= -1;
	}
	return -1;
}
