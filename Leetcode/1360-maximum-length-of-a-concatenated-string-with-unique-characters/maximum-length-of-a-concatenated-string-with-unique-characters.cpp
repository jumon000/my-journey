class Solution {
public:
    int n;
    vector<unordered_map<int,int>> dp;

    int solve(int pos, int mask, vector<string>& arr){

        if(pos == n)
            return 0;

        if(dp[pos].count(mask))
            return dp[pos][mask];

        int notTake = solve(pos + 1, mask, arr);

        int newMask = mask;
        bool valid = true;

        for(char c : arr[pos]){

            int bit = c - 'a';

            if(newMask & (1 << bit)){
                valid = false;
                break;
            }

            newMask |= (1 << bit);
        }

        int take = 0;

        if(valid)
            take = arr[pos].size() + solve(pos + 1, newMask, arr);

        return dp[pos][mask] = max(take, notTake);
    }

    int maxLength(vector<string>& arr) {

        n = arr.size();
        dp.resize(n);

        return solve(0, 0, arr);
    }
};