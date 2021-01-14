using namespace std;

// O(n^2) time | O(n) space
int numberOfBinaryTreeTopologies(int n) {
  vector<int> cache{1};
  for (int m = 1; m < n + 1; m++) {
  	int numberOfTrees = 0;
  	for (int leftTreeSize = 0; leftTreeSize < m; leftTreeSize++) {
  		int rightTreeSize = m - 1 - leftTreeSize;
  		int numberOfLeftTrees = cache[leftTreeSize];
  		int numberOfRightTrees = cache[rightTreeSize];
  		numberOfTrees += numberOfLeftTrees * numberOfRightTrees;
  	}
  	cache.push_back(numberOfTrees);
  } 
  return cache[n];
}
