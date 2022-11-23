#include "../headers/astarboi.h"
int heuristic(std::pair<int, int> u, std::pair<int, int> dest) {
	// diagonal distance: http://theory.stanford.edu/~amitp/GameProgramming/Heuristics.html
	int d_x = abs(u.first - dest.first);
	int d_y = abs(u.second - dest.second);
	int D = 1, D2 = 1;
	return D * (d_x + d_y) + (D2 - 2 * D) * std::min(d_x, d_y);
}

void astar_init(
	int m, int n,
	std::vector<std::vector<bool>>& is_closed,
	std::vector<std::vector<int>>& g,
	std::vector<std::vector<std::pair<int, int>>>& parent
) {
	for (int i = 0; i < m; i++) {
		is_closed.push_back(std::vector<bool>(n, false));
		g.push_back(std::vector<int>(n, INF));
		parent.push_back(std::vector<std::pair<int, int>>(n, INVALID_NODE));
	}
}

std::vector<std::pair<int, int>> astar_trace(
	std::pair<int, int> root, std::pair<int, int> dest,
	const std::vector<std::vector<std::pair<int, int>>>& parent
) {
	std::vector<std::pair<int, int>> trace;
	for (std::pair<int, int> u = dest; trace.push_back(u), (u != root); u = parent[u.first][u.second]);
	return std::vector<std::pair<int, int>>(trace.rbegin(), trace.rend());
}

std::vector<std::pair<int, int>> astar(std::vector<std::vector<int>>& a, int start_x, int start_y, int dest_x, int dest_y) {
	std::pair<int, int> root(start_x, start_y), dest(dest_x, dest_y);

	int m = a.size(), n = a[0].size();

	std::vector<std::vector<bool>> is_closed;
	std::vector<std::vector<int>> g;
	std::vector<std::vector<std::pair<int, int>>> parent;
	astar_init(m, n, is_closed, g, parent);

	std::priority_queue<pq_iter, std::vector<pq_iter>, std::greater<pq_iter>> pq;
	g[start_x][start_y] = 0;
	pq.push(std::make_pair(g[start_x][start_y] + heuristic(root, dest), root));

	while (!pq.empty()) {
		auto iter_top = pq.top();
		pq.pop();
		std::pair<int, int> u = iter_top.second;
		int u_x = u.first, u_y = u.second;
		if (is_closed[u_x][u_y]) {
			continue;
		}
		if (u == dest) {
			auto trace = astar_trace(root, dest, parent);
			for (auto u_ : trace) {
				//std::cout << "-> (" << u_.first << ", " << u_.second << ") ";
			}
			//std::cout << std::endl;
			return trace;
		}
		is_closed[u_x][u_y] = true;
		for (int k = 0; k < 4; k++) {
			int v_x = u_x + dx[k], v_y = u_y + dy[k];
			if (0 <= v_x && v_x < m && 0 <= v_y && v_y < n && a[v_x][v_y] == 0) {
				int w_uv = 1;
				int g_uv = g[u_x][u_y] + w_uv;
				if (g[v_x][v_y] > g_uv) {
					std::pair<int, int> v(v_x, v_y);
					parent[v_x][v_y] = u;
					g[v_x][v_y] = g_uv;
					pq.push(std::make_pair(g[v_x][v_y] + heuristic(v, dest), v));
				}
			}
		}
	}
	return std::vector<std::pair<int, int>>();
}