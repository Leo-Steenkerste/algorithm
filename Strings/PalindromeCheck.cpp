using namespace std;

bool isPalindrome(string str) {
  int leftIdx = 0;
	int rightIdx = str.length() - 1;
	while (leftIdx < rightIdx) {
		if (str[leftIdx] != str[rightIdx]) {
			return false;
		}
		leftIdx++;
		rightIdx--;
	}
  return true;
}