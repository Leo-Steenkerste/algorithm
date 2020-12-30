
#include <vector> 

using namespace std; 

// 0(w^2 * h) time 1 0(w) space - where w and h 
// are the width and height of the input iArray 
vector<double> waterfallStreams(vector<vector<double>> iArray, int iSource) { 
	vector<double> aRowAbove = iArray[0]; 
	// 11 use -1 to represent water, since 1 is used for a block. 
	aRowAbove[iSource] = -1; 
	
	for (int aRow = 1; aRow < iArray.size(); aRow++) { 
		vector<double> aCurrentRow = iArray[aRow]; 

		for (int idx = 0; idx < aRowAbove.size(); idx++) { 
			double aValueAbove = aRowAbove[idx]; 
			bool hasWaterAbove = aValueAbove < 0; 
			bool hasBlock = aCurrentRow[idx] == 1.0; 

			if (!hasWaterAbove) { 
				continue; 
			} 

			if (!hasBlock) { 
				// If no block in the current column, move the water down. 
				aCurrentRow[idx] += aValueAbove; 
				continue;
			}

			double aSplitWater = aValueAbove / 2; 
			// Move water right. 

			int rightIdx = idx; 

			while (rightIdx + 1 < aRowAbove.size()) { 
				rightIdx += 1; 
				if (aRowAbove[rightIdx] == 1.0) { // if there is a block in the way 
					break;  
				}

				if (aCurrentRow[rightIdx] != 1) { // if there is no block below us 
					aCurrentRow[rightIdx] += aSplitWater; break; 
				} 
			} 

			// Move water left. 

			int leftIdx = idx;
			while (leftIdx - 1 >= 0) { 
				leftIdx -= 1; 
				if (aRowAbove[leftIdx] == 1.0) { // if there is a block in the way 
				break; 
				}
				if (aCurrentRow[leftIdx] != 1.0) { // if there is no block below us 
					aCurrentRow[leftIdx] += aSplitWater;
					break; 
				}
			}
		}

		aRowAbove = aCurrentRow;
	}

	vector<double> aFinalPercentages;
	for (double num : aRowAbove) {
		if (num == 0) {
			aFinalPercentages.push_back(num);
		}
		else {
			aFinalPercentages.push_back(num * -100);
		}
	}
	return aFinalPercentages;
}

