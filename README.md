# Leetcode-3342.-Find-Minimum-Time-to-Reach-Last-Room-II

🚀 Min Time To Reach (Dijkstra Variant on Grid with Move Parity)
🧠 Problem Description
You are given a 2D grid where each cell contains a time value. Starting from cell (0, 0), you must reach cell (m-1, n-1). You can move in four directions (up, down, left, right), and your cost to move depends on:

Whether the current time is sufficient to enter the next cell.

A parity switch that adds an extra unit time every alternate move.

---

📌 Approach
This problem is solved using a modified Dijkstra's algorithm:

We use a min-heap priority queue to always expand the cell with the lowest current cost.

We track whether the current move is even or odd using a boolean flag move, which flips after every step.

The cost is computed by waiting if needed (max(0, grid[newi][newj] - cost)) and includes a penalty of +1 for time to move and +(move == 1) to simulate alternating behavior.

---

📦 Data Structures Used

visited[i][j]: Stores the minimum time required to reach cell (i, j).

Priority queue (min-heap) with elements of the form:
((cost, move_parity), (i, j))

---

⏱️ Time Complexity
O(m × n × log(m × n))

Each cell is processed once at minimal cost.

Each operation in the priority queue takes log(m × n) time.

There are m × n cells in total.

---

📦 Space Complexity
O(m × n)

For the visited matrix.

For storing elements in the priority queue.
