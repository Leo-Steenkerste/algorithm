// TODO : Add Description
// TODO : Add exception on input parameters
// TODO : Create template version


#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> &iArray, int iToMove) 
{
	int i = 0, j = iArray.size() - 1;

	while (i < j) 
	{
		while (i < j && iArray[j] == iToMove) 
		{
			j--;
		}
		
		if(iArray[i] == iToMove) 
		{
			swap(iArray[i], iArray[j]);
		}
		
		i++;
	}
	return iArray;
} 