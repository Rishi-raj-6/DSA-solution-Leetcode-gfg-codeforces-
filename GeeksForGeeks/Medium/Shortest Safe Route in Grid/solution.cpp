class Solution {
public:
    int shortestPath(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int dr[]={-1,1,0,0},dc[]={0,0,-1,1};
        vector<vector<int>> safe(n,vector<int>(m,1));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(mat[i][j]==0){
                    safe[i][j]=0;
                    for(int k=0;k<4;k++){
                        int r=i+dr[k],c=j+dc[k];
                        if(r>=0&&r<n&&c>=0&&c<m)
                            safe[r][c]=0;
                    }
                }
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
            if(safe[i][0]){
                q.push({{i,0},1});
                vis[i][0]=1;
            }
        while(!q.empty()){
            auto [p,d]=q.front();
            q.pop();
            int r=p.first,c=p.second;
            if(c==m-1)return d;
            for(int k=0;k<4;k++){
                int nr=r+dr[k],nc=c+dc[k];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&safe[nr][nc]&&!vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({{nr,nc},d+1});
                }
            }
        }
        return -1;
    }
};