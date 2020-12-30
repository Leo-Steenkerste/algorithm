// TODO : Add Description
// TODO : Add exception on input parameters
// TODO : Create template version

using namespace std;


// O(n) time | O(n) space - where n is the total number of elements in the iArray
vector<int> spiralTraverse(vector<vector<int>> iArray) {
	if(iArray.size() == 0) {
		return {};
	}

	vector<int> result = {};
	int aStartRow = 0, aEndRow = iArray.size() - 1, aStartCol = 0, aEndCol = iArray[0].size() - 1;

	while (aStartRow <= aEndRow && aStartCol <= aEndCol) {
		for (int aCol = aStartCol; aCol <= aEndCol; aCol++) {
			result.push_back(iArray[aStartRow][aCol]);
		}

		for (int aRow = aStartRow + 1; aRow <= aEndRow; aRow++) {
			result.push_back(iArray[aRow][aEndCol]);
		}

		for (int aCol = aEndCol - 1; aCol >= aStartCol; aCol--) {
			/* Handle the edge case when there's a single row
			   in the middle of the matrix. In this case, we don't 
			   want to double-count the values in this row, which 
			   we've already counted in the first for loop above.
			   exemple : {"iArray": [[1, 2, 3, 4], [10, 11, 12, 5], [9, 8, 7, 6]]} */
			if (aStartRow == aEndRow) {
				break;
			}
			result.push_back(iArray[aEndRow][aCol]);
		}

		for (int aRow = aEndRow - 1; aRow > aStartRow; aRow--) {
			/* Handle the edge case when there's a single column
			   in the middle of the matrix. In this case, we don't 
			   want to double-count the values in this column, which 
			   we've already counted in the first for loop above.
			   exemple : {"iArray": [[1, 2, 3], [12, 13, 4], [11, 14, 5], [10, 15, 6], [9, 8, 7]]} */
			if(aStartCol == aEndCol) {
				break;
			}
			result.push_back(iArray[aRow][aStartCol]);
		}

		aStartRow++;
		aEndRow--;
		aStartCol++;
		aEndCol--;
	}
	return result;
}