### ✅ C++ Code: Minimum Time to Reach with Cell Parity Consideration

```cpp
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Initialize visited matrix with max integer values
        vector<vector<int>> visited(m, vector<int>(n, INT_MAX));
        visited[0][0] = 0;

        // Directions: up, down, left, right
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Min-heap priority queue to store {cost, {i, j}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;
        q.push({0, {0, 0}}); 

        while (!q.empty()) {
            auto [cost, coord] = q.top();
            q.pop();
            int i = coord.first, j = coord.second;

            // Skip if this path is not optimal
            if (cost > visited[i][j]) continue;

            for (auto& dir : directions) {
                int newi = i + dir[0];
                int newj = j + dir[1];

                if (newi < 0 || newi >= m || newj < 0 || newj >= n) continue;

                // Wait time if the target cell has a higher required time
                int wait = max(0, grid[newi][newj] - cost);

                // Add extra +1 if the cell index sum is even (parity penalty)
                int newcost = cost + wait + 1 + ((newi + newj) % 2 == 0); 

                if (visited[newi][newj] > newcost) {
                    visited[newi][newj] = newcost;
                    q.push({newcost, {newi, newj}});
                }
            }
        }

        return visited[m - 1][n - 1];
    }
};
