
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool isValidPart(string str);
string join(vector<string> strings);

// O(1) time | O(1) space
vector<string> validIPAddresses(string str) {
	vector<string> ipAddressesFound;

	for(int i = 1; i < min((int)str.length(), 4); i++) {
		vector<string> currentIPAddressParts = {"", "", "", ""};

		currentIPAddressParts[0] = str.substr(0, i);
		if (!isValidPart(currentIPAddressParts[0])) {
			continue;
		}

		for (int j = i + 1; j < i + min((int)str.length() - i, 4); j++) {
			currentIPAddressParts[1] = str.substr(i, j - i);
			if (!isValidPart(currentIPAddressParts[1])) {
				continue;
			}

			for(int k = j + 1; k < j + min((int) str.length() - j, 4); k++) {
				currentIPAddressParts[2] = str.substr(j, k - j);
				currentIPAddressParts[3] = str.substr(k);

				if (isValidPart(currentIPAddressParts[2]) &&
					isValidPart(currentIPAddressParts[3])) {
					ipAddressesFound.push_back(join(currentIPAddressParts));
				}
			}
		} 
	}

	return ipAddressesFound;
}

bool isValidPart(string str) {
	int stringAsInt = stoi(str);

	if (stringAsInt > 255) {
		return false;
	}

	return str.length() == to_string(stringAsInt).length(); // check for leading 0
}

string join(vector<string> strings) {
	string s;
	for (int l = 0; l < strings.size(); l++) {
		s += strings[l];
		if (l < strings.size() - 1) {
			s += ".";
		}
	}
	return s;
}
