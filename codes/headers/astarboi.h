#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>

const int INF = 1000000000;
const int dx[8] = { 0,  0, -1,  1, -1, -1,  1, 1 };
const int dy[8] = { 1, -1,  0,  0, -1,  1, -1, 1 };
const std::pair<int, int> INVALID_NODE(-1, -1);

typedef std::pair<int, std::pair<int, int>> pq_iter;

int heuristic(std::pair<int, int> u, std::pair<int, int> dest);
void astar_init(
	int m, int n,
	std::vector<std::vector<bool>>& is_closed,
	std::vector<std::vector<int>>& g,
	std::vector<std::vector<std::pair<int, int>>>& parent
);
std::vector<std::pair<int, int>> astar_trace(
	std::pair<int, int> root, std::pair<int, int> dest,
	const std::vector<std::vector<std::pair<int, int>>>& parent
);
std::vector<std::pair<int, int>> astar(std::vector<std::vector<int>>& a, int start_x, int start_y, int dest_x, int dest_y);
