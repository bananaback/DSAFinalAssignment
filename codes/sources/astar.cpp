#include "../headers/astar.h"

void remove(std::vector<std::pair<int, int>>& currentSet, const std::pair<int, int>& currentNode) {
	for (size_t i = 0; i < currentSet.size(); i++) {
		if (currentNode == currentSet[i]) {
			currentSet.erase(currentSet.begin() + i);
			return;
		}
	}
}

bool contains(const std::vector<std::pair<int, int>>& currentSet, const std::pair<int, int>& currentNode) {
	for (size_t i = 0; i < currentSet.size(); i++) {
		if (currentNode == currentSet[i]) return true;
	}
	return false;
}

int getDistance(const std::pair<int, int>& nodeA, const std::pair<int, int>& nodeB) {
	int dstY = std::abs(nodeA.first - nodeB.first);
	int dstX = std::abs(nodeA.second - nodeB.second);
	if (dstY > dstX) {
		return 14 * dstX + 10 * (dstY - dstX);
	}
	return 14 * dstY + 10 * (dstX - dstY);
}

std::vector<std::pair<int, int>> retracePath(const std::pair<int, int>& startNode, const std::pair<int, int>& endNode, const std::vector<std::vector<std::pair<int, int>>>& parent) {
	std::vector<std::pair<int, int>> path;
	std::pair<int, int> currentNode = endNode;
	while (currentNode != startNode) {
		path.push_back(currentNode);
		currentNode = parent[currentNode.first][currentNode.second];
	}
	std::reverse(path.begin(), path.end());
	return path;
}

std::vector<std::pair<int, int>> pathFinding(const std::vector<std::vector<int>>& map, const std::pair<int, int>& startNode, const std::pair<int, int>& targetNode) {
	if (map[startNode.first][startNode.second] != 0 || map[targetNode.first][targetNode.second] != 0) {
		return std::vector<std::pair<int, int>>();
	}

	std::vector<std::pair<int, int>> openSet;
	std::vector<std::pair<int, int>> closedSet;
	std::vector<std::vector<int>> f(MAP_HEIGHT, std::vector<int>(MAP_WIDTH, 999999));
	std::vector<std::vector<int>> g(MAP_HEIGHT, std::vector<int>(MAP_WIDTH, 999999));
	std::vector<std::vector<int>> h(MAP_HEIGHT, std::vector<int>(MAP_WIDTH, 999999));
	std::vector<std::vector<std::pair<int, int>>> parent(MAP_HEIGHT, std::vector<std::pair<int, int>>(MAP_WIDTH, std::make_pair(0, 0)));

	openSet.push_back(startNode);
	while (!openSet.empty()) {
		std::pair<int, int> currentNode = openSet[0];
		for (size_t i = 1; i < openSet.size(); i++) {
			if (f[openSet[i].first][openSet[i].second] < f[currentNode.first][currentNode.second]
				|| f[openSet[i].first][openSet[i].second] == f[currentNode.first][currentNode.second]
				&& h[openSet[i].first][openSet[i].second] < h[currentNode.first][currentNode.second]) {
				currentNode = openSet[i];
			}
		}
		remove(openSet, currentNode);
		closedSet.push_back(currentNode);
		if (currentNode == targetNode) {
			return retracePath(startNode, targetNode, parent);
		}

		std::vector<std::pair<int, int>> neighbourList;
		for (int y = -1; y <= 1; y++) {
			for (int x = -1; x <= 1; x++) {
				if (x == 0 && y == 0) continue;
				if (std::abs(x) == 1 && std::abs(y) == 1) continue;
				int checkY = currentNode.first + y;
				int checkX = currentNode.second + x;
				if (checkY >= 0 && checkY < MAP_HEIGHT && checkX >= 0 && checkX < MAP_WIDTH) {
					// neighbour
					std::pair<int, int> neighbour = std::make_pair(checkY, checkX);
					neighbourList.push_back(neighbour);
				}
			}
		}

		for (size_t i = 0; i < neighbourList.size(); i++) {
			std::pair<int, int> neighbour = neighbourList[i];
			if (map[neighbour.first][neighbour.second] != 0 || contains(closedSet, neighbour)) {
				continue;
			}
			int newMovementCostToNeighbour = g[currentNode.first][currentNode.second] + getDistance(currentNode, neighbour);
			if (newMovementCostToNeighbour < g[neighbour.first][neighbour.second] || !contains(openSet, neighbour)) {
				g[neighbour.first][neighbour.second] = newMovementCostToNeighbour;
				h[neighbour.first][neighbour.second] = getDistance(neighbour, targetNode);
				parent[neighbour.first][neighbour.second] = currentNode;

				if (!contains(openSet, neighbour)) {
					openSet.push_back(neighbour);
				}
			}
		}
	}
}