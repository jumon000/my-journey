class Solution {
public:
    using ull = unsigned long long;
    const ull BASE = 131;

    vector<ull> pref, power;
    vector<int> dp;
    int n;
    string s;

    ull getHash(int l, int r) {
        return pref[r + 1] - pref[l] * power[r - l + 1];
    }

    int solve(int i) {

        if (i == n)
            return 0;

        if (dp[i] != -1)
            return dp[i];
        //op-1
        int ans = 1;
        //try all length 
        for (int len = 1; i + 2 * len <= n; len++) {

            if (getHash(i, i + len - 1) ==
                getHash(i + len, i + 2 * len - 1)) {

                ans = max(ans, 1 + solve(i + len));
            }
        }

        return dp[i] = ans;
    }

    int deleteString(string str) {

        s = str;
        n = s.size();

        pref.assign(n + 1, 0);
        power.assign(n + 1, 1);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] * BASE + (s[i] - 'a' + 1);
            power[i + 1] = power[i] * BASE;
        }

        dp.assign(n, -1);

        return solve(0);
    }
};