class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>&grid,int k) {
        int m=grid.size(),n=grid[0].size();
        int t=m*n;
        k %=t;
        vector<vector<int>> ans(m, vector<int>(n));
        for (int r=0;r<m;r++) {
            for (int c=0;c<n;c++) {
                int x=(r*n+c+k)%t;
                ans[x/n][x%n]=grid[r][c];
            }
        }
        return ans;
    }
};