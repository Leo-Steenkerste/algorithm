#include <vector>
#include <climits> 

using namespace std; 
// 0(n^2) time 10(n^2) space 
int palindromePartitioningMinCuts(string iPalindromePartition) { 
	vector<vector<bool>> palindromes(iPalindromePartition.length(), vector<bool>(iPalindromePartition.length(), false));
	for (int i = 0; i < iPalindromePartition.length(); i++) { 
		palindromes[i][i] = true;
	} 
	for (int length = 2; length < iPalindromePartition.length() + 1; length++) { 
		for (int i = 0; i < iPalindromePartition.length() - length + 1; i++) { 
	 		int j = i + length - 1; 
	 		if (length == 2) { 
	 			palindromes[i][j] = (iPalindromePartition[i] == iPalindromePartition[j]); 
			} 
			else {
				palindromes[i][j] = (iPalindromePartition[i] == iPalindromePartition[j] && palindromes[i + 1][j - 1]); 
			} 
		}
	}
	vector<int> cuts(iPalindromePartition.length(), INT_MAX);
	for (int i = 0; i < iPalindromePartition.length(); i++) { 
		if(palindromes[0][i]) { 
			cuts[i] = 0; 
		} 
		else { 
			cuts[i] = cuts[i - 1] + 1;
			for (int j = 1; j < i; j++) { 
				if (palindromes[j][i] && cuts[j - 1] + 1 < cuts[i]) {
					cuts[i] = cuts[j - 1] + 1; 
				} 
			}
		}
	}
	return cuts[iPalindromePartition.length() - 1];
}						
