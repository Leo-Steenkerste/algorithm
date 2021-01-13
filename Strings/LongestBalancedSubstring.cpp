
#include <algorithm>

using namespace std;

int getLongestBalancedInDirection(string str, bool leftToRight);


// O(n) time | O(1) space - where n is the length of the input string
int longestBalancedSubstring(string str) {
	return max(getLongestBalancedInDirection(str, true),
				getLongestBalancedInDirection(str, false));
}

int getLongestBalancedInDirection(string str, bool leftToRight) {
	char openingParens = leftToRight ? '(' : ')';
	int startIdx = leftToRight ? 0 : str.length() - 1;
	int step = leftToRight ? 1 : -1;

	int maxLength = 0;

	int openingCount = 0;
	int closingCount = 0;

	int idx = startIdx;
	while (idx >= 0 && idx < str.length()) {
		char c = str[idx];

		if (c == openingParens) {
			openingCount++;
		}
		else {
			closingCount++;
		}

		if (openingCount == closingCount) {
			maxLength = max(maxLength, closingCount * 2);
		}
		else if (closingCount > openingCount) {
			openingCount = 0;
			closingCount = 0;
		}

		idx += step;
	}

	return maxLength;
}
