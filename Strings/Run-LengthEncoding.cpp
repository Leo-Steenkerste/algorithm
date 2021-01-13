#include <vector>

using namespace std; 

// O(n) time | O(n) space - where n is the length of the input string
string runLengthEncoding(string str) {
	// The input string is guaranteed to be non-empty.
	// so our first run will be of at least length 1.
	vector<char> encodedStringCharacters;
	int currentRunLength = 1;

	for (int i = 1; i < str.size(); i++) {
		char currentCharacter = str[i]; 
		char previousCharacter = str[i - 1];

		if(currentCharacter != previousCharacter || currentRunLength == 9) {
			encodedStringCharacters.push_back(to_string(currentRunLength)[0]);
			encodedStringCharacters.push_back(previousCharacter);
			currentRunLength = 0;
		}
		currentRunLength++;
	}

	//Handle the last run.
	encodedStringCharacters.push_back(to_string(currentRunLength)[0]);
	encodedStringCharacters.push_back(str[str.size() - 1]);

	string encodedString(encodedStringCharacters.begin(), encodedStringCharacters.end());

	return encodedString;
}
