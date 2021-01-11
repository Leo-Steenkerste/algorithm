#include <vector>
using namespace std;

vector<int> buildPattern(string substr);
bool doesMatch(string str, string substr, vector<int> pattern);


// O (n + m) time | O(m) space
bool knuthMorrisPrattAlgorithm(string str, string substr) {
  vector<int> pattern = buildPattern(substr);
  return doesMatch(str, substr, pattern);
}

vector<int> buildPattern(string substr) {
	vector<int> pattern(substr.size(), -1);
	int j = 0, i = 1;
	while (i < substr.size()) {
		if (substr[i] == substr[j]) {
			pattern[i] = j;
			i++; 
			j++;
		}
		else if (j > 0) {
			j = pattern[j - 1] + 1;
		}
		else {
			i++;
		}
	}
	return pattern;
}


bool doesMatch(string str, string substr, vector<int> pattern) {
	int i = 0, j = 0;
	while (i + substr.size() - j <= str.size()) {
		if (str[i] == substr[j]) {
			if (j == substr.size() - 1) {
				return true;
			}
			i++;
			j++;
		} 
		else if (j > 0) {
			j = pattern[j - 1] + 1;
		}
		else {
			i++;
		}
	}
	return false;
}