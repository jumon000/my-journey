class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;

        long long res = k;
        long long ops = 0;

        for (int x : nums) {
            if (res < x) {
                long long need = (x - res + k - 1) / k; // ceil((x-res)/k)
                ops += need;
                res += need * 1LL * k;
            }
            res -= x;
        }

        ops %= MOD;
        return (ops * (ops + 1) / 2) % MOD;
    }
};