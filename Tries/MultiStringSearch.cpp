#include <vector>
#include <unordered_map>
using namespace std;

class TrieNode {
	public : 
		unordered_map<char, TrieNode *> children;
		string word;
};

class Trie {
	public :
		TrieNode *root;
		char endSymbol;

	Trie() {
		this->root = new TrieNode;
		this->endSymbol = '*';
	}

	void insert(string iStr) {
		TrieNode *current = this->root;
		for (int i = 0; i < iStr.length(); i++) {
			char letter = iStr[i]; 
			if (current->children.find(letter) == current->children.end()) {
				TrieNode *newNode = new TrieNode();
				current->children.insert({letter, newNode});
			}
			current = current->children[letter];
		}
		current->children.insert({this->endSymbol, NULL});
		current->word = iStr;
	}
};

void findSmallStringsIn(string iStr, int startIdx, Trie *iTrie, unordered_map<string, bool> *iContainedStrings);

vector<bool> multiStringSearch(string iBigString, vector<string> iSmallStrings) {
  Trie *iTrie = new Trie();
  for (string smallString : iSmallStrings) {
  	iTrie->insert(smallString);
  }
  unordered_map<string, bool> iContainedStrings;
  for(int i = 0; i < iBigString.length(); i++) {
  	findSmallStringsIn(iBigString, i, iTrie, &iContainedStrings);
  }
  vector<bool> solution;
  for (string smallString : iSmallStrings) {
  	solution.push_back(iContainedStrings.find(smallString) != iContainedStrings.end());
  }
  return solution;
}

void findSmallStringsIn(string iStr, int startIdx, Trie *iTrie, unordered_map<string, bool> *iContainedStrings) {
	TrieNode *currentNode = iTrie->root;
	for (int i = startIdx; i < iStr.length(); i++) {
		if(currentNode->children.find(iStr[i]) == currentNode->children.end()) {
			break;
		}
		currentNode = currentNode->children[iStr[i]];
		if(currentNode->children.find(iTrie->endSymbol) != currentNode->children.end()) {
			iContainedStrings->insert({currentNode->word, true});
		}
	}
}