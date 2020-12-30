// TODO : Add Description
// TODO : Add exception on input parameters
// TODO : Create template version

#include <vector>

using namespace std;

bool isOutOfBounds(int iRow, int iCol, int iHeight, int iWidth);

// O(n) time | O(n) space - where n is the total number of elements in two-dimensional array
vector<int> zigzagTraverse(vector<vector<int>> iArray) {
	int aHeight = iArray.size() - 1, aWidth = iArray[0].size() - 1, aRow = 0, aCol = 0; 
	vector<int> aResult = {};
	bool isGoingDown = true;

	while (!isOutOfBounds(aRow, aCol, aHeight, aWidth)) {
		aResult.push_back(iArray[aRow][aCol]);
		if (isGoingDown) {
			if (aCol == 0 || aRow == aHeight) {
				isGoingDown = false;
				if (aRow == aHeight) {
					aCol++;
				}
				else {
					aRow++;
				}
			}
			else {
				aRow++;
				aCol--;
			}
		}
		else {
			if (aRow == 0 || aCol == aWidth) {
				isGoingDown = true;
				if (aCol == aWidth) {
					aRow++;
				}
				else {
					aCol++;
				}
			}
			else
			{
				aRow--;
				aCol++;
			}
		}
	}
	return aResult;
}

bool isOutOfBounds(int iRow, int iCol, int iHeight, int iWidth) {
	return iRow < 0 || iRow > iHeight || iCol < 0 || iCol > iWidth;
}