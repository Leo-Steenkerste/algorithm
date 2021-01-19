#include <vector>
using namespace std;

vector<int> searchForRange(vector<int> array, int target);
void alteredBinarySearch(vector<int> array, int target, int left, int right, vector<int> *finalRange, bool goLeft);

vector<int> searchForRange(vector<int> array, int target) {
	vector<int> finalRange{-1, -1};
	alteredBinarySearch(array, target, 0, array.size() - 1, &finalRange, true);
	alteredBinarySearch(array, target, 0, array.size() - 1, &finalRange, false);
	return finalRange;
}


void alteredBinarySearch(vector<int> array, int target, int left, int right, vector<int> *finalRange, bool goLeft) {
	while (left <= right) {
		int mid = (left + right) / 2;
		if (array[mid] < target) {
			left = mid + 1;
		}
		else if (array[mid] > target) {
			right = mid - 1;
		}
		else {
			if(goLeft) {
				if(mid == 0 || array[mid - 1] != target) {
					finalRange->at(0) = mid;
					return;
				}
				else {
					right = mid - 1;
				}
			}
			else {
				if(mid == array.size() - 1 || array[mid + 1] != target) {
					finalRange->at(1) = mid;
					return;
				}
				else {
					left = mid + 1;
				}
			}
		}
	}
}