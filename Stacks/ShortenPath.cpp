#include <sstream>
using namespace std;

bool isImportantToken(string token);

// O(n) time | O(n) space - where n is the length of the path
string shortenPath(string path) {
	bool startsWithSlash = path[0] == '/';
	istringstream iss(path);
	string token;

	vector<string> tokens;
	vector<string> filteredTokens;
	while (getline(iss, token, '/')) {
		tokens.push_back(token);
	}
	copy_if(tokens.begin(), tokens.end(), back_inserter(filteredTokens), isImportantToken);
	vector<string> stack;
	if (startsWithSlash) {
		stack.push_back("");
	}
	for (string token : filteredTokens) {
		if (token == "..") {
			if (stack.size() == 0 || stack[stack.size() - 1] == "..") {
				stack.push_back(token);
			}
			else if (stack[stack.size() - 1] != "") {
				stack.pop_back();
			}
		}
		else {
			stack.push_back(token);
		}
	}

	if (stack.size() == 1 && stack[0] == "") {
		return "/";
	}

	ostringstream oss;
	for (auto i = 0; i < stack.size(); i++) {
		if (i != 0) {
			oss << "/";
		}
		oss << stack[i];
	}
  return oss.str();
}


bool isImportantToken(string token) {
	return token.length() && token != ".";
}