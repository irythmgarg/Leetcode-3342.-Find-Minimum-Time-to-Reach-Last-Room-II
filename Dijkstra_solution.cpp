// Dijkstra's Algorithm on Grid with Alternating Move Cost Consideration
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, INT_MAX));
        visited[0][0] = 0;

        // 4-directional movement (up, down, left, right)
        vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        // Priority queue: ((current_cost, current_move_parity), (i, j))
        // move_parity: false for even step, true for odd step (alternating behavior)
        priority_queue<pair<pair<int, bool>, pair<int, int>>, 
                       vector<pair<pair<int, bool>, pair<int, int>>>, 
                       greater<>> q;

        q.push({{0, 0}, {0, 0}});  // Start from cell (0, 0) with cost 0 and even step

        while (!q.empty()) {
            int cost = q.top().first.first;
            bool move = q.top().first.second;
            int i = q.top().second.first;
            int j = q.top().second.second;
            q.pop();

            if (cost > visited[i][j]) continue;

            for (auto& dir : directions) {
                int newi = i + dir[0];
                int newj = j + dir[1];

                if (newi < 0 || newi >= m || newj < 0 || newj >= n) continue;

                // Calculate the cost considering grid constraints and move parity
                int newcost = cost + max(0, grid[newi][newj] - cost) + 1 + (move == 1);

                if (visited[newi][newj] > newcost) {
                    visited[newi][newj] = newcost;
                    q.push({{newcost, !move}, {newi, newj}});
                }
            }
        }

        return visited[m-1][n-1];  // Return minimum time to reach bottom-right corner
    }
};
