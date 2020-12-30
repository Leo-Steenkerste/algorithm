//Validate Subsequence
/*
Take in input two array of interger A and B 
Return true if B is a subsequence of A
 Given two non-empty arrays of integers, write a function that determines
  whether the second array is a subsequence of the first one.

 
  A subsequence of an array is a set of numbers that aren't necessarily adjacent
  in the array but that are in the same order as they appear in the array. For
  instance, the numbers [1, 3, 4]  form a subsequence of the array [1, 2, 3, 4], 
  and so do the numbers [2, 4]. 
  Note that a single number in an array and the array itself are both valid 
  subsequences of the array.

 */

// TODO : Add exception on input parameters
// TODO : Create template version


// O(n) time | O(1) space - n length of the array
using namespace std;
bool isValidSubsequence(vector<int> iArray, vector<int> iSequence) {
	int aArrIdx = 0;
	int aSeqIdx = 0;
	while (aArrIdx < iArray.size() && aSeqIdx < iSequence.size()) {
		if(iArray[aArrIdx] == iSequence[aSeqIdx]) {
			aSeqIdx++;
		}
		aArrIdx++;
	}
	return aSeqIdx == iSequence.size();
}

//C++ 11
// O(n) time | O(1) space - n length of the array
using namespace std;

bool isValidSubsequence(vector<int> iArray, vector<int> iSequence) {
	int aSeqIdx = 0;
	for (auto aValue : iArray) {
		if(aSeqIdx == iSequence.size()) {
			break;
		}
		if(iSequence[aSeqIdx] == aValue) {
			aSeqIdx++;
		}
		
	}
	return aSeqIdx == iSequence.size();
}

