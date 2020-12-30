// TODO : Add Description
// TODO : Add exception on input parameters
// TODO : Create template version

using namespace std;

bool isMonotonic(vector<int> iArray)
{
	bool is_non_decreasing = true;
	bool is_non_increasing = true; 
	for (int i = 1; i < iArray.size(); i++) 
	{
		if(iArray[i] < iArray[i - 1]) 
		{
			is_non_decreasing = false;
		}
		if(iArray[i] > iArray[i - 1]) 
		{
			is_non_increasing = false;
		}
	}
	return is_non_decreasing || is_non_increasing;
}