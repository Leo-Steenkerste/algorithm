#include <vector>
using namespace std;

int MinNumberOfCoinsForChange(int iTargetNumber, vector<int> iDenoms) {
  vector<int> aNumOfCoins(iTargetNumber + 1, INT_MAX);
  aNumOfCoins[0] = 0;
  int aToCompare = 0;
  for (int denom : iDenoms) {
  	for (int amount = 0; amount < aNumOfCoins.size(); amount++) {
  		if(denom <= amount) {
  			if(aNumOfCoins[amount - denom] == INT_MAX) {
  				aToCompare = aNumOfCoins[amount - denom];
  			}
  			else {
  				aToCompare = aNumOfCoins[amount - denom] + 1;
  			}
  			aNumOfCoins[amount] = min(aNumOfCoins[amount], aToCompare);
  		}
  	}
  }
  return aNumOfCoins[iTargetNumber] != INT_MAX ? aNumOfCoins[iTargetNumber] : -1;
}
