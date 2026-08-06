class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        queue<int> q;
        vector<vector<int>> adj(n);

        for (auto &it : invocations) {
            adj[it[0]].push_back(it[1]);
        }

        unordered_set<int> st;

        q.push(k);
        st.insert(k);

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {

                if (!st.count(it)) {
                    q.push(it);
                    st.insert(it);
                }
            }
        }

        bool flag = false;

        for (auto &it : invocations) {
            int u = it[0];
            int v = it[1];

            if (!st.count(u) && st.count(v)) {
                flag = true;
                break;
            }
        }

        vector<int> ans;

        if (flag) {
            for (int i = 0; i < n; i++)
                ans.push_back(i);
            return ans;
        }

        for (int i = 0; i < n; i++) {
            if (!st.count(i))
                ans.push_back(i);
        }

        return ans;
    }
};