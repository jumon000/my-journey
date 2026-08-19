class Solution {
public:
    vector<vector<int>> adj;
    vector<int> nums;
    vector<int> ans;
    vector<pair<int, int>> best;

    void dfs(int u, int parent, int depth) {
        int bestDepth = -1;
        int bestNode = -1;

        for (int x = 1; x <= 50; x++) {
            if (best[x].first == -1)
                continue;

            if (gcd(x, nums[u]) == 1) {
                if (best[x].first > bestDepth) {
                    bestDepth = best[x].first;
                    bestNode = best[x].second;
                }
            }
        }

        ans[u] = bestNode;

        pair<int, int> old = best[nums[u]];
        best[nums[u]] = {depth, u};

        for (int v : adj[u]) {
            if (v == parent)
                continue;

            dfs(v, u, depth + 1);
        }

        best[nums[u]] = old;
    }

    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        this->nums = nums;

        int n = nums.size();

        adj.assign(n, {});
        ans.assign(n, -1);
        best.assign(51, {-1, -1});

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1, 0);

        return ans;
    }
};