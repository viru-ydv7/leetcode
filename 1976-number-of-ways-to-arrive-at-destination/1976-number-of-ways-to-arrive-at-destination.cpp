class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : roads) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [distance, node] = pq.top();
            pq.pop();

            if (distance > dist[node]) continue;

            for (auto &it : adj[node]) {
                int neighbour = it.first;
                long long d = it.second;

                long long newDist = distance + d;

                if (newDist < dist[neighbour]) {
                    dist[neighbour] = newDist;
                    ways[neighbour] = ways[node];
                    pq.push({newDist, neighbour});
                }
                else if (newDist == dist[neighbour]) {
                    ways[neighbour] = (ways[neighbour] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1] % MOD;
    }
};