class Solution {
public:
    int n;
    vector<int> prefix;
    vector<vector<int>> dp;

    int solve(int pos, int sum, int size, int m, vector<int>& piles) {

        if (pos >= n)
            return sum;

        if (dp[pos][m] != -1)
            return dp[pos][m];

        int curr_sum = 0;

        int overall = prefix[n] - prefix[pos];

        int op = INT_MIN;

        for (int x = 1; x <= 2 * m && pos + x <= n; x++) {

            curr_sum = prefix[pos + x] - prefix[pos];

            int opponent = solve(
                pos + x,
                overall - curr_sum,
                size,
                max(m, x),
                piles
            );

            op = max(op, overall - opponent);
        }

        return dp[pos][m] = op;
    }

    int stoneGameII(vector<int>& piles) {

        n = piles.size();

        prefix.assign(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + piles[i];

        dp.assign(n + 1, vector<int>(n + 1, -1));

        return solve(0, 0, n, 1, piles);
    }
};