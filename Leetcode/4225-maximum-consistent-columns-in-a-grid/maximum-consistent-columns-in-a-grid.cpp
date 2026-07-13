class Solution {
public:
    bool isvalid(int last, int curr,vector<vector<int>>&grid,int limit){
        int m = grid.size();
        for(int i =0;i<m;i++){
            if(abs(grid[i][curr] - grid[i][last])> limit){
                return false;
                
            }
        }
        return true;
    }

    int solve(vector<vector<int>> & grid,int last , int curr , int limit,  vector<vector<int>>&dp){
        int m = grid.size();
        int n = grid[0].size();
        if(curr==n){
            return 0;
        }
        if(dp[last+1][curr]!=-1){
            return dp[last+1][curr];
        }
        int nottake = solve(grid,last,curr+1,limit,dp);
        int take=0;
        if(last==-1|| isvalid(last,curr,grid,limit)){
            take=1+solve(grid,curr,curr+1,limit,dp);
        }
        return dp[last+1][curr]= max(take,nottake);
    }
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(grid,-1,0,limit,dp);
        
    }
};