class Solution {
public:
    long long solve(int pos, vector<int>& nums, int limit) {

        if (pos < 0)
            return 0;

        if (nums[pos] <= limit) {
            return solve(pos - 1, nums, nums[pos]);
        }

        int pieces = (nums[pos] + limit - 1) / limit;  

        int newLimit = nums[pos] / pieces;

        return (pieces - 1LL) + solve(pos - 1, nums, newLimit);
    }

    long long minimumReplacement(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return 0;

        return solve(n - 2, nums, nums[n - 1]);
    }
};