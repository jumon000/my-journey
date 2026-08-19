class Solution {
public:

    int longestSubsequence(vector<int>& nums) {
        
        int n = nums.size(), _xor = 0;

        bool nonZero = false;

        for(int i = 0; i < n; ++i) {

            _xor ^= nums[i];

            if(nums[i]) {

                nonZero = true;
            }
        }

        if(_xor) {

            return n;
        }

        if(nonZero) {

            return n - 1;
        }
        else{

            return 0;
        }
    }
};