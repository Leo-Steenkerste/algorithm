#include <vector>
#include <algorithm>
using namespace std;

// O(n) time | O(n) space - where n is the length of the 
vector<int> sunsetViews(vector<int> buildings, string direction) {
 	vector<int> candidateBuildings;

 	int startIdx = buildings.size() - 1;
 	int step = -1;

 	if (direction == "EAST") {
 		startIdx = 0;
 		step = 1;
 	}

 	int idx = startIdx;
 	while (idx >= 0 && idx < buildings.size()) {
 		int buildingHeight = buildings[idx];

 		while (candidateBuildings.size() > 0 &&
 				buildings[candidateBuildings[candidateBuildings.size()  - 1]] <= buildingHeight) {
 			candidateBuildings.pop_back();
 		}

 		candidateBuildings.push_back(idx);

 		idx += step;
 	}

 	if (direction == "WEST") {
 		reverse(candidateBuildings.begin(), candidateBuildings.end());
 	}

 	return candidateBuildings;
}
