class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
                int minVal = INT_MAX;
        int maxVal = INT_MIN;

        vector<int> pref(nums.size());
        vector<int> suff(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            maxVal = max(maxVal, nums[i]);
            pref[i] = maxVal;
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            minVal = min(minVal, nums[i]);
            suff[i] = minVal;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (pref[i] - suff[i] <= k)
                return i;
        }

        return -1;

    }
};