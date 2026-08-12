class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
        }

        const int INF = 1e9;

        
        vector<vector<int>> dist(n, vector<int>(k + 1, INF));

        using T = tuple<int, int, int>;

        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {

            auto [currDist, node, freq] = pq.top();
            pq.pop();

            if (currDist != dist[node][freq])
                continue;

            if (node == n - 1)
                return currDist;

            for (auto [next, weight] : adj[node]) {

                int newFreq;

                if (labels[next] == labels[node]) {

                    if (freq + 1 > k)
                        continue;

                    newFreq = freq + 1;
                }
                else {
                    newFreq = 1;
                }

                int newDist = currDist + weight;

                if (newDist < dist[next][newFreq]) {

                    dist[next][newFreq] = newDist;

                    pq.push({
                        newDist,
                        next,
                        newFreq
                    });
                }
            }
        }

        return -1;
    }
};