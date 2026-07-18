class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {

        unordered_map<string,int> mp;
        int ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {

            string cur = to_string(nums[i]);

            if(mp.count(cur))
                ans = min(ans, i - mp[cur]);

            string rev = cur;
            reverse(rev.begin(), rev.end());

            int k = 0;
            while(k < rev.size() && rev[k] == '0')
                k++;

            if(k == rev.size())
                rev = "0";
            else
                rev = rev.substr(k);

            mp[rev] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};