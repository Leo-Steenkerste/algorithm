#include <vector>
#include <limits>
using namespace std;

struct Item {
	int vertex, distance;
};


class MinHeap {
public: 
	vector<Item> heap;
	unordered_map<int, int> vertexMap;

	MinHeap(vector<Item> array) {
		for (auto item : array) {
			vertexMap[item.vertex] = item.vertex;
		}
		heap = buildHeap(array);
	}	

	// O(n) time | O(1) space
	vector<Item> buildHeap(vector<Item> &array) {
		int firstParentIdx = (array.size() - 2) / 2;
		for(int currentIdx = firstParentIdx + 1; currentIdx >= 0; currentIdx--) {
			siftDown(currentIdx, array.size() - 1, array);
		}
		return array;
	}

	bool isEmpty() {
		return heap.size() == 0;
	}

	// O(log(n)) time | O(1) space 
	void siftDown(int currentIdx, int endIdx, vector<Item> &heap) {
		int childOneIdx = currentIdx * 2 + 1;
		while (childOneIdx <= endIdx) {
			int childTwoIdx = currentIdx * 2 + 2 <= endIdx ? currentIdx * 2 + 2 : -1;
			int idxToSwap;
			if (childTwoIdx != -1 && heap[childTwoIdx].distance < heap[childOneIdx].distance) {
				idxToSwap = childTwoIdx;
			}
			else {
				idxToSwap = childOneIdx;
			}
			if (heap[idxToSwap].distance < heap[currentIdx].distance) {
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
		while (currentIdx > 0 && heap[currentIdx].distance < heap[parentIdx].distance) {
			swap(currentIdx, parentIdx);
			currentIdx = parentIdx;
			parentIdx = (currentIdx - 1) / 2;
		}
	}

	Item remove() {
		swap(0, heap.size() - 1);
		auto [vertex, distance] = heap.back();
		heap.pop_back();
		vertexMap.erase(vertex);
		siftDown(0, heap.size() - 1, heap);
		return Item{vertex, distance};
	}

	void update(int vertex, int value) {
		heap[vertexMap[vertex]] = Item{vertex, value};
		siftUp(vertexMap[vertex]);
	}

	void swap(int i, int j) {
		vertexMap[heap[i].vertex] = j;
		vertexMap[heap[j].vertex] = i;
		auto temp = heap[i];
		heap[i] = heap[j];
		heap[j] = temp;
	}
};

// O((v + e) * log(v)) time | O(v) space - where v is the number
// of vertices and e is the number of edges in the input graph
vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) {
  int numberOfVertices = edges.size();


  vector<int> minDistances(edges.size(), numeric_limits<int>::max());
  minDistances[start] = 0;

  vector<Item> minDistancesPairs;
  for (int i = 0; i < edges.size(); ++i) {
  	minDistancesPairs.push_back(Item{i, numeric_limits<int>::max()});
  }

  MinHeap minDistancesHeap(minDistancesPairs);
  minDistancesHeap.update(start, 0);

  while (!minDistancesHeap.isEmpty()) {
  	auto [vertex, currentMinDistance] = minDistancesHeap.remove();

  	if(currentMinDistance == numeric_limits<int>::max()) {
  		break;
  	}
  	for (auto edge: edges[vertex]) {
  		auto destination = edge[0];
  		auto distanceToDestination = edge[1];
  		auto newPathDistance = currentMinDistance + distanceToDestination;
  		auto currentDestinationDistance = minDistances[destination];
  		if (newPathDistance < currentDestinationDistance) {
  			minDistances[destination] = newPathDistance;
  			minDistancesHeap.update(destination, newPathDistance);
  		}
  	}
  }

  vector<int> finalDistances;
  for (auto distance : minDistances) {
  	if (distance == numeric_limits<int>::max()) {
  		finalDistances.push_back(-1);
  	}
  	else {
  		finalDistances.push_back(distance);
  	}
  }
  return finalDistances;
}