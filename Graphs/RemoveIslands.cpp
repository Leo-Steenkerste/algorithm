#include <vector>
using namespace std;


void changeOnesConnectedToBorderToTwos(vector<vector<int>> &matrix,
										int startRow, int startCol);

vector<vector<int>> getNeighbors(vector<vector<int>> &matrix, int row, int col);

vector<vector<int>> removeIslands(vector<vector<int>> matrix) {
  for (int row = 0; row < matrix.size(); row++) {
  	for(int col = 0; col < matrix[row].size(); col++) {
  		bool rowIsBorder = row == 0 || row == matrix.size() - 1;
  		bool colIsBorder = col == 0 || col == matrix[row].size() - 1;
  		bool isBorder = rowIsBorder || colIsBorder;

  		if (!isBorder) {
  			continue;
  		}

  		if (matrix[row][col] != 1) {
  			continue;
  		}

  		changeOnesConnectedToBorderToTwos(matrix, row, col);
  	}
  }

  for (int row = 0; row < matrix.size(); row++) {
  	for (int col = 0; col < matrix[row].size(); col++) {
  		int color = matrix[row][col];
  		if (color == 1) {
  			matrix[row][col] = 0;
  		}
  		else if (color == 2) {
  			matrix[row][col] = 1;
  		}
  	}
  }

  return matrix;
}


void changeOnesConnectedToBorderToTwos(vector<vector<int>> &matrix,
										int startRow, int startCol) {
	vector<vector<int>> stack = {{startRow, startCol}};

	while (stack.size() > 0) {
		auto currentPosition = stack[stack.size() - 1];
		stack.pop_back();
		int currentRow = currentPosition[0];
		int currentCol = currentPosition[1];

		matrix[currentRow][currentCol] = 2;

		auto neighbors = getNeighbors(matrix, currentRow, currentCol);
		for (auto neighbor : neighbors) {
			int row = neighbor[0];
			int col = neighbor[1];

			if (matrix[row][col] != 1) {
				continue;
			}
			stack.push_back(neighbor);
		}
	}
}

vector<vector<int>> getNeighbors(vector<vector<int>> &matrix, int row, int col) {
	vector<vector<int>> neighbors;
	int numRows = matrix.size();
	int numCols = matrix[row].size();

	if (row - 1 >= 0) {
		neighbors.push_back(vector<int>{row - 1, col}); //UP
	}
	if (row + 1 < numRows) {
		neighbors.push_back(vector<int>{row + 1, col}); //DOWN
	}
	if (col - 1 >= 0) {
		neighbors.push_back(vector<int>{row, col - 1}); //LEFT
	}
	if (col + 1 < numCols) {
		neighbors.push_back(vector<int>{row, col + 1}); //RIGHT
	}

	return neighbors;
}