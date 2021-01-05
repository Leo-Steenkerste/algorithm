#include <vector>
#include <climits>

using namespace std;


int maxProfitWithKTransactions(vector<int> iPrices, int iNumberOfTransaction) {
  if (iPrices.size() == 0) {
  	return 0;
  }

  vector<int> evenProfits(iPrices.size());
  vector<int> oddProfits(iPrices.size());
  for (int i = 1; i < iNumberOfTransaction + 1; i++) {
		int maxThusFar = INT_MIN;
  	vector<int> *currentProfits;
  	vector<int> *previousProfits;
  	if (i % 2 == 1) {
  		currentProfits = &oddProfits;
  		previousProfits = &evenProfits;
  	}
  	else {
  		currentProfits = &evenProfits;
  		previousProfits = &oddProfits;
  	}
  	for (int d = 1; d < iPrices.size(); ++d) {
  		maxThusFar = max(maxThusFar, previousProfits->at(d - 1) - iPrices[d - 1]);
  		currentProfits->at(d) = max(currentProfits->at(d - 1), maxThusFar + iPrices[d]);
  	}
  }
  return iNumberOfTransaction % 2 == 0 ? evenProfits[iPrices.size() - 1] : oddProfits[iPrices.size() - 1];
}
