// Two number sum
/*
Take an array containing int, and a target sum as input.
Return an array containing the three int that make the target number
Return an empty array if nothing was found
*/

// TODO : Add exception on input parameters
// TODO : Create template version


#include <vector>
#include <algorithm>

using namespace std;

// 0(n²) time | O(n) space
vector<vector<int>> threeNumberSum(vector<int> iArray, int iTargetSum)
{
	sort(iArray.begin(), iArray.end());
	vector<vector<int>> aTriplets;
	for (int i = 0; i < iArray.size() - 2; i++) 
	{
		int aLeft = i + 1;
		int aRight = iArray.size() - 1; 
		while (aLeft < aRight) 
		{
			int aCurrentSum = iArray[i] + iArray[aLeft] + iArray[aRight];
			if(aCurrentSum == iTargetSum) 
			{
				aTriplets.push_back({iArray[i], iArray[aLeft], iArray[aRight]});
				aRight--;
				aLeft++;
			}
			else if (aCurrentSum < iTargetSum)
			{
				aLeft++;
			}
			else if (aCurrentSum > iTargetSum)
			{
				aRight--;
			}
		}
	}
	return aTriplets;
}