#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int iTarget, vector<int> iDenoms) {
  vector<int> aWays(iTarget + 1, 0);
  aWays[0] = 1;
  for(int aDenom : iDenoms) {
  	for(int aAmount = 1; aAmount < iTarget + 1; aAmount++) {
  		if(aDenom <= aAmount) {
  			aWays[aAmount] += aWays[aAmount - aDenom];
  		}
  	}
  }
  return aWays[iTarget];
}
