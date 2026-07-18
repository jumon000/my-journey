class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<string> board;
    int n;

    vector<vector<pair<int,int>>> dp;
    vector<vector<int>> vis;

    pair<int,int> solve(int i,int j){

        if(i>=n || j>=n || board[i][j]=='X')
            return {-1,0};

        if(i==n-1 && j==n-1)
            return {0,1};

        if(vis[i][j])
            return dp[i][j];

        vis[i][j]=1;

        pair<int,int> ans={-1,0};

        int dr[3]={1,0,1};
        int dc[3]={0,1,1};

        for(int k=0;k<3;k++){

            auto cur=solve(i+dr[k],j+dc[k]);

            if(cur.first==-1) continue;

            int score=cur.first;

            if(board[i][j]!='E')
                score+=board[i][j]-'0';

            if(score>ans.first){
                ans.first=score;
                ans.second=cur.second;
            }
            else if(score==ans.first){
                ans.second=(ans.second+cur.second)%MOD;
            }
        }

        return dp[i][j]=ans;
    }

    vector<int> pathsWithMaxScore(vector<string>& b) {

        board=b;
        n=board.size();

        dp.assign(n,vector<pair<int,int>>(n));
        vis.assign(n,vector<int>(n,0));

        auto res=solve(0,0);

        if(res.first==-1)
            return {0,0};

        return {res.first,res.second};
    }
};