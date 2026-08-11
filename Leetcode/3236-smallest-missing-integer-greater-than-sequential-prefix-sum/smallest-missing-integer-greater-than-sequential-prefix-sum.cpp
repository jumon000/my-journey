class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        vector<int>a=nums;
        sort(a.begin(),a.end());

        int i=1;
        int n=nums.size();
        int sum=nums[0];
        while(i<n && nums[i]==nums[i-1]+1){
            
            sum+=nums[i];
            i++;
        }

        unordered_map<int,int>map;
        for(auto it:nums){
            if(!map[it]){
                map[it]=1;
            }
        }

        for(int i=sum;i<=max(sum,a[n-1]+1);i++){
            if(!map[i]){
                return i;
            }
        }

        return 0;


    }
};