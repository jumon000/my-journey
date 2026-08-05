class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {

        int n = graph.size();

        if (n == 1)
            return 0;

        queue<pair<int, int>> q;  

        vector<vector<int>> dist(n, vector<int>(1 << n, -1));

        for (int i = 0; i < n; i++) {
            int mask = (1 << i);
            q.push({i, mask});
            dist[i][mask] = 0;
        }

        while (!q.empty()) {

            auto [node, mask] = q.front();
            q.pop();

            if (mask == (1 << n) - 1)
                return dist[node][mask];

            for (int next : graph[node]) {

                int newMask = mask | (1 << next);

                if (dist[next][newMask] == -1) {

                    dist[next][newMask] = dist[node][mask] + 1;
                    q.push({next, newMask});
                }
            }
        }

        return -1;
    }
};