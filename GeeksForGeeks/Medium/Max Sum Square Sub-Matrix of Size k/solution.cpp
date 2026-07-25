class Solution{
public:
    int maximumSum(vector<vector<int>>& mat,int k){
        int n=mat.size(),ans=INT_MIN;
        vector<vector<int>> pre(n+1,vector<int>(n+1));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                pre[i][j]=mat[i-1][j-1]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
        for(int i=0;i<=n-k;i++)
            for(int j=0;j<=n-k;j++)
                ans=max(ans,pre[i+k][j+k]-pre[i][j+k]-pre[i+k][j]+pre[i][j]);
        return ans;
    }
};