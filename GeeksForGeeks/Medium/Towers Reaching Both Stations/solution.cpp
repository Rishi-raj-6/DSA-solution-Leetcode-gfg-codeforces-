class Solution{
public:
    void bfs(queue<pair<int,int>>&q,vector<vector<int>>&vis,vector<vector<int>>&mat){
        int n=mat.size(),m=mat[0].size();
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dx[k],ny=y+dy[k];
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&!vis[nx][ny]&&mat[nx][ny]>=mat[x][y]){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    }

    int countCoordinates(vector<vector<int>>&mat){
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>p(n,vector<int>(m,0)),qv(n,vector<int>(m,0));
        queue<pair<int,int>>qp,qq;

        for(int i=0;i<n;i++){
            if(!p[i][0]){
                p[i][0]=1;
                qp.push({i,0});
            }
            if(!qv[i][m-1]){
                qv[i][m-1]=1;
                qq.push({i,m-1});
            }
        }

        for(int j=0;j<m;j++){
            if(!p[0][j]){
                p[0][j]=1;
                qp.push({0,j});
            }
            if(!qv[n-1][j]){
                qv[n-1][j]=1;
                qq.push({n-1,j});
            }
        }

        bfs(qp,p,mat);
        bfs(qq,qv,mat);

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(p[i][j]&&qv[i][j])ans++;
            }
        }
        return ans;
    }
};