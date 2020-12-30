// TODO : Add Description
// TODO : Add exception on input parameters
// TODO : Create template version

using namespace std;

// O(n) time | O (1) space - where n is the lenght of the input array
int longestPeak(vector<int> iArray) {
	int aLongestPeakLenght = 0; 
	int i = 1;

	while (i < int(iArray.size() - 1 )) {
		bool isPeak = iArray[i - 1] < iArray[i] && iArray[i] > iArray[i + 1];
		if (!isPeak) {
			i++;
			continue;
		}

		int aLeftIdx = i - 2;
		while (aLeftIdx >= 0 && iArray[aLeftIdx] < iArray[aLeftIdx + 1]) {
			aLeftIdx--;
		}

		int aRightIdx = i + 2;

		while (aRightIdx < iArray.size() && iArray[aRightIdx] < iArray[aRightIdx - 1]) {
			aRightIdx++;
		}
		int currentPeakLenght = aRightIdx - aLeftIdx - 1;
		aLongestPeakLenght = max(aLongestPeakLenght, currentPeakLenght);
		i = aRightIdx;
	}
	return aLongestPeakLenght;
}