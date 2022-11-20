#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

#define MAP_WIDTH 32
#define MAP_HEIGHT 18

void remove(std::vector<std::pair<int, int>>& currentSet, const std::pair<int, int>& currentNode);
bool contains(const std::vector<std::pair<int, int>>& currentSet, const std::pair<int, int>& currentNode);
int getDistance(const std::pair<int, int>& nodeA, const std::pair<int, int>& nodeB);
std::vector<std::pair<int, int>> retracePath(const std::pair<int, int>& startNode, const std::pair<int, int>& endNode, const std::vector<std::vector<std::pair<int, int>>>& parent);
std::vector<std::pair<int, int>> pathFinding(const std::vector<std::vector<int>>& map, const std::pair<int, int>& startNode, const std::pair<int, int>& targetNode);