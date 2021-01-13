#include <vector>
#include <unordered_map>
using namespace std;

struct Point {
  int x;
  int y;
};

unordered_map<string, bool> getCoordsTable(vector<Point> coords);
int getRectangleCount(vector<Point> coords, unordered_map<string, bool> coordsTable);
bool isInUpperRight(Point coord1, Point coord2);
string coordToString(Point coord);


int rectangleMania(vector<Point> coords) {
  unordered_map<string, bool> coordsTable = getCoordsTable(coords);
  return getRectangleCount(coords, coordsTable);
}

unordered_map<string, bool> getCoordsTable(vector<Point> coords) {
	unordered_map<string, bool> coordsTable;
	for (Point coord : coords) {
		string coordString = coordToString(coord);
		coordsTable.insert({coordString, true});
	}
	return coordsTable;
}

int getRectangleCount(vector<Point> coords, unordered_map<string, bool> coordsTable) {
	int rectangleCount = 0;
	for (Point coord1 : coords) {
		for (Point coord2 : coords) {
			if (!isInUpperRight(coord1, coord2)) {
				continue;
			}
			string upperCoordString = coordToString(Point({coord1.x, coord2.y}));
			string rightCoorString = coordToString(Point({coord2.x, coord1.y}));
			if (coordsTable.find(upperCoordString) != coordsTable.end() &&
				coordsTable.find(rightCoorString) != coordsTable.end()) {
				rectangleCount++;
			}
		}
	}
	return rectangleCount;
}

bool isInUpperRight(Point coord1, Point coord2) {
	return coord2.x > coord1.x && coord2.y > coord1.y;
}

string coordToString(Point coord) {
	return to_string(coord.x) + "-" + to_string(coord.y);
}