class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : flights) {
            int u = e[0];
            int v = e[1];
            int cost = e[2];

            adj[u].push_back({v, cost});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // {stops, {node, cost}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            // Can't use more than k stops.
            if (stops > k)
                continue;

            for (auto &nbr : adj[node]) {
                int nextNode = nbr.first;
                int edgeCost = nbr.second;

                int newCost = cost + edgeCost;

                if (newCost < dist[nextNode]) {
                    dist[nextNode] = newCost;
                    q.push({stops + 1, {nextNode, newCost}});
                }
            }
        }

        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};