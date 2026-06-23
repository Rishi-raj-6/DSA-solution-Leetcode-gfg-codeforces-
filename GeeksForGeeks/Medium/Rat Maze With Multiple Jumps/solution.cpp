class Solution {
public:
    bool solve(int i,int j,vector<vector<int>>& mat,vector<vector<int>>& ans,vector<vector<int>>& dp,int n){
        if(i<0||j<0||i>=n||j>=n) return false;
        if(i==n-1&&j==n-1){
            ans[i][j]=1;
            return true;
        }
        if(mat[i][j]==0) return false;
        if(dp[i][j]==-1) return false;

        ans[i][j]=1;
        int steps=mat[i][j];

        for(int jump=1;jump<=steps;jump++){
            if(j+jump<n&&solve(i,j+jump,mat,ans,dp,n)) return true;
            if(i+jump<n&&solve(i+jump,j,mat,ans,dp,n)) return true;
        }

        ans[i][j]=0;
        dp[i][j]=-1;
        return false;
    }

    vector<vector<int>> shortestDist(vector<vector<int>>& mat){
        int n=mat.size();
        vector<vector<int>> ans(n,vector<int>(n,0));
        vector<vector<int>> dp(n,vector<int>(n,0));

        if(solve(0,0,mat,ans,dp,n)) return ans;
        return {{-1}};
    }
};