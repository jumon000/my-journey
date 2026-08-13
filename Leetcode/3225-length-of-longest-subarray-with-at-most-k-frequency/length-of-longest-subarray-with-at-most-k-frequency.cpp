class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        unordered_map<int,int>map;
        int n=nums.size();
        int ans=INT_MIN;

        int i=0;
        int j=0;

        while(i<n && j<=i){

            int a=nums[i];
            map[a]++;
            if(map[a]>k){
                while(j<=i && map[a]>k){
                    if(map[nums[j]]!=0){
                        map[nums[j]]--;
                    }
                    j++;
                }
            }
            ans=max(ans,i-j+1);
            i++;
        }

        return ans;
    }
};