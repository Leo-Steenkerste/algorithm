#include <unordered_map>
#include <stack>

using namespace std;

bool balancedBrackets(string str) {
	string openingBrackets = "([{";
	string closingBrackets = ")]}";
	unordered_map<char, char> matchingBrackets{
		{')', '('},
		{']', '['},
		{'}', '{'}
	};
	stack<char> stack;
	for(char character : str) {
		if (openingBrackets.find(character) != string::npos) {
			stack.push(character);
		}
		else if (closingBrackets.find(character) != string::npos) {
			if(stack.size() == 0) {
				return false;
			}
			if(stack.top() == matchingBrackets[character]) {
				stack.pop();
			}
			else {
				return false;
			}
		}
	}
  return stack.size() == 0;
}
