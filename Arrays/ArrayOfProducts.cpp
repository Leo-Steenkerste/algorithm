// TODO : Add Description
// TODO : Add exception on input parameters
// TODO : Create template version


#include <vector>

using namespace std;

// O(n) time | O(n) space - where n is the number of elements in the input iArray
vector<int> iArrayOfProducts(vector<int> iArray) {
	vector<int> aProducts(iArray.size(), 1);

	int aLeftRunningProduct = 1;
	for (int i = 0; i < iArray.size(); i++) {
		aProducts[i] = aLeftRunningProduct;
		aLeftRunningProduct *= iArray[i];
	}

	int aRightRunningProduct = 1;
	for (int i = iArray.size() - 1; i >= 0; i--) {
		aProducts[i] *= aRightRunningProduct;
		aRightRunningProduct *= iArray[i];
	}
	
	return aProducts;
}