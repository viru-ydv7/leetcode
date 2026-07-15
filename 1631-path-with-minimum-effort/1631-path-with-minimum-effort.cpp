class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();

        vector<vector<int>> efforts(r, vector<int>(c, INT_MAX));
        efforts[0][0] = 0;

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        pq.push({0, {0, 0}});

        vector<pair<int, int>> directions = {
            {-1, 0}, // up
            {0, 1},  // right
            {1, 0},  // down
            {0, -1}  // left
        };

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            // Destination reached
            if (row == r - 1 && col == c - 1) {
                return diff;
            }

            for (auto &e : directions) {
                int newRow = row + e.first;
                int newCol = col + e.second;

                if (newRow < 0 || newRow >= r || newCol < 0 || newCol >= c) {
                    continue;
                }

                int edgeDiff = abs(heights[newRow][newCol] - heights[row][col]);

                // Maximum effort encountered on this path
                int newEffort = max(diff, edgeDiff);

                if (newEffort < efforts[newRow][newCol]) {
                    efforts[newRow][newCol] = newEffort;
                    pq.push({newEffort, {newRow, newCol}});
                }
            }
        }

        return 0;
    }
};