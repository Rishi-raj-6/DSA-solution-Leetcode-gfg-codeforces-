class Solution{
public:
    int ans=-1;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    void dfs(vector<vector<int>>&mat,int x,int y,int xd,int yd,int cnt){
        if(x==xd&&y==yd){
            ans=max(ans,cnt);
            return;
        }

        mat[x][y]=0;

        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(nx>=0&&nx<mat.size()&&ny>=0&&ny<mat[0].size()&&mat[nx][ny]==1){
                dfs(mat,nx,ny,xd,yd,cnt+1);
            }
        }

        mat[x][y]=1;
    }

    int longestPath(vector<vector<int>>&mat,int xs,int ys,int xd,int yd){
        if(mat[xs][ys]==0||mat[xd][yd]==0)return -1;
        dfs(mat,xs,ys,xd,yd,0);
        return ans;
    }
};