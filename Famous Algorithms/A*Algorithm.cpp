#include <limits>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

class Node {
public: 
	string id;
	int row;
	int col;
	int value;
	int distanceFromStart;
	int estimatedDistanceToEnd;
	Node *cameFrom;

	Node(int row, int col, int value) {
		this->id = to_string(row) + '-' + to_string(col);
		this->row = row;
		this->col = col;
		this->value = value;
		this->distanceFromStart = numeric_limits<int>::max();
		this->estimatedDistanceToEnd = numeric_limits<int>::max();
		this->cameFrom = NULL;
	}
};


class MinHeap {
public:
	vector<Node *> heap;
	unordered_map<string, int> nodePositionsInHeap;

	MinHeap(vector<Node *> array) {
		for (int i = 0; i < array.size(); i++) {
			auto node = array[i];
			nodePositionsInHeap[node->id] = i;
		}
		heap = buildHeap(array);
	}

	// O(n) time | O(1) space
	vector<Node *> buildHeap(vector<Node *> &array) {
		int firstParentIdx = (array.size() - 2) / 2;
		for (int currentIdx = firstParentIdx + 1; currentIdx >= 0; currentIdx--) {
			siftDown(currentIdx, array.size() - 1, array);
		}
		return array;
	}

	bool isEmpty() {
		return heap.size() == 0;
	}


	// O(log(n)) time | O(1) space
	void siftDown(int currentIdx, int endIdx, vector<Node *> &array) {
		int childOneIdx = currentIdx * 2 + 1;
		while (childOneIdx <= endIdx) {
			int childTwoIdx = currentIdx * 2 + 2 <= endIdx ? currentIdx * 2 + 2 : -1;
			int idxToSwap;
			if(childTwoIdx != -1 && array[childTwoIdx]->estimatedDistanceToEnd < 
				 												heap[childOneIdx]->estimatedDistanceToEnd) {
				idxToSwap = childTwoIdx;
			}
			else {
				idxToSwap = childOneIdx;
			}
			if (array[idxToSwap]->estimatedDistanceToEnd < 
					array[currentIdx]->estimatedDistanceToEnd) {
				swap(currentIdx, idxToSwap);
				currentIdx = idxToSwap;
				childOneIdx = currentIdx * 2 + 1;
			}
			else {
				return;
			}
		}
	}

	// O(log(n)) time | O(1) space
	void siftUp(int currentIdx) {
		int parentIdx = (currentIdx - 1) / 2;
		while (currentIdx > 0 && heap[currentIdx]->estimatedDistanceToEnd <
					 									heap[parentIdx]->estimatedDistanceToEnd) {
			swap(currentIdx, parentIdx);
			currentIdx = parentIdx;
			parentIdx = (currentIdx - 1) / 2;
		}
	}

	Node *remove() {
		if (isEmpty()) {
			return NULL;
		}

		swap(0, heap.size() - 1);
		auto node = heap.back();
		heap.pop_back();
		nodePositionsInHeap.erase(node->id);
		siftDown(0, heap.size() - 1, heap);
		return node;
	}

	void insert(Node *node) {
		heap.push_back(node);
		nodePositionsInHeap[node->id] = heap.size() - 1;
		siftUp(heap.size() - 1);		
	}

	void swap(int i, int j) {
		nodePositionsInHeap[heap[i]->id] = j;
		nodePositionsInHeap[heap[j]->id] = i;
		auto temp = heap[i];
		heap[i] = heap[j];
		heap[j] = temp;
	}

	bool containsNode(Node *node) {
		return nodePositionsInHeap.find(node->id) != nodePositionsInHeap.end();
	}

	void update(Node *node) {
		siftUp(nodePositionsInHeap[node->id]);		
	}
};


vector<vector<int>> reconstructPath(Node *endNode);
vector<Node *> getNeightboringNodes(Node *node, vector<vector<Node *>> &nodes);
int calculateManhattanDistance(Node *currentNode, Node *endNode);
vector<vector<Node *>> initializeNodes(vector<vector<int>> graph);

// O(w * h * log(w * h)) time | O(w * h) space - where
// w is the width of the graph and h is the height
vector<vector<int>> aStarAlgorithm(int startRow, int startCol, int endRow,
                                   int endCol, vector<vector<int>> graph) {
  auto nodes = initializeNodes(graph);
  auto startNode = nodes[startRow][startCol];
  auto endNode = nodes[endRow][endCol];

  startNode->distanceFromStart = 0;
  startNode->estimatedDistanceToEnd = 
		calculateManhattanDistance(startNode, endNode);

  MinHeap nodesToVisit(vector<Node *>{startNode});

  while (!nodesToVisit.isEmpty()) {
  	auto currentMinDistanceNode = nodesToVisit.remove();

  	if(currentMinDistanceNode == endNode) {
  		break;
  	}

  	auto neighbors = getNeightboringNodes(currentMinDistanceNode, nodes);

  	for (auto neighbor : neighbors) {
  		if (neighbor->value == 1) {
  			continue;
  		}

  		int tentativeDistanceToNeighbor = 
				currentMinDistanceNode->distanceFromStart + 1;

  		if(tentativeDistanceToNeighbor >= neighbor->distanceFromStart) {
  			continue;
  		}

  		neighbor->cameFrom = currentMinDistanceNode;
  		neighbor->distanceFromStart = tentativeDistanceToNeighbor;
  		neighbor->estimatedDistanceToEnd = 
				tentativeDistanceToNeighbor + 
				calculateManhattanDistance(neighbor, endNode);

  		if(!nodesToVisit.containsNode(neighbor)) {
  			nodesToVisit.insert(neighbor);
  		}
  		else {
  			nodesToVisit.update(neighbor);
  		}
  	}
  }
  return reconstructPath(endNode);
}

vector<vector<Node *>> initializeNodes(vector<vector<int>> graph) {
	vector<vector<Node *>> nodes;

	for (int i = 0; i < graph.size(); i++) {
		nodes.push_back(vector<Node *>{});
		for (int j = 0; j < graph[i].size(); j++) {
			nodes[i].push_back(new Node(i, j, graph[i][j]));
		}
	}

	return nodes;
}

int calculateManhattanDistance(Node *currentNode, Node *endNode) {
	int currentRow = currentNode->row; 
	int currentCol = currentNode->col;
	int endRow = endNode->row;
	int endCol = endNode->col;

	return abs(currentRow - endRow) + abs(currentCol - endCol); 	
}	


vector<Node *> getNeightboringNodes(Node *node, vector<vector<Node *>> &nodes) {
	vector<Node *> neighbors;

	int numRows = nodes.size();
	int numCols = nodes[0].size();

	int row = node->row;
	int col = node->col;

	if (row < numRows - 1) { //Down
		neighbors.push_back(nodes[row + 1][col]);
	}

	if (row > 0) { //UP
		neighbors.push_back(nodes[row - 1][col]);
	}

	if (col < numCols - 1) { // Right
		neighbors.push_back(nodes[row][col + 1]);
	}

	if (col > 0) { //Left
		neighbors.push_back(nodes[row][col - 1]);
	}

	return neighbors;
}



vector<vector<int>> reconstructPath(Node *endNode) {
	if (endNode->cameFrom == nullptr) {
		return vector<vector<int>>{};
	}

	Node *currentNode = endNode;
	vector<vector<int>> path;


	while (currentNode != nullptr) {
		path.push_back(vector<int>{currentNode->row, currentNode->col});
		currentNode = currentNode->cameFrom;
	}

	reverse(path.begin(), path.end());
	return path;
}