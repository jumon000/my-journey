class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size();

        unordered_map<char, vector<int>> pos;

        for (int i = 0; i < station.size(); i++) {
            pos[station[i]].push_back(i);
        }

        vector<int> left(n);

        int prev = -1;

        for (int i = 0; i < n; i++) {
            auto &v = pos[skill[i]];

            auto it = upper_bound(v.begin(), v.end(), prev);

            left[i] = *it;
            prev = left[i];
        }

        vector<int> right(n);

        int next = station.size();

        for (int i = n - 1; i >= 0; i--) {
            auto &v = pos[skill[i]];

            auto it = lower_bound(v.begin(), v.end(), next);

            --it;

            right[i] = *it;
            next = right[i];
        }

        int ans = 0;

        for (int i = 1; i < n; i++) {
            ans = max(ans, right[i] - left[i - 1]);
        }

        return ans;
    }
};