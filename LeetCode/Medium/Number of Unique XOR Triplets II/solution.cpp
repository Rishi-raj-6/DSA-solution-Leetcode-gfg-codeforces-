class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int M=2048;
        vector<vector<char>> dp(4,vector<char>(M,0));
        vector<char> vis(M,0);

        dp[0][0]=1;

        for (int x:nums) {
            vis[x]=1;
            for (int c=2;c>=0;c--) {
                for (int v=0;v<M;v++) {
                    if (dp[c][v])
                        dp[c+1][v^x]=1;
                }
            }
        }

        int ans=0;

        for (int v=0;v<M;v++) {
            if (vis[v]||dp[3][v])
                ans++;
        }

        return ans;
    }
};