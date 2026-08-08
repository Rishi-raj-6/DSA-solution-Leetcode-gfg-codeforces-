class Solution{
public:
    vector<int> p;

    int find(int x){
        return p[x]==x?x:p[x]=find(p[x]);
    }

    int minEdgesReq(int n,vector<vector<int>>& edges){
        if(edges.size()<n-1) return -1;
        p.resize(n);
        for(int i=0;i<n;i++) p[i]=i;
        int c=n;
        for(auto &e:edges){
            int u=find(e[0]),v=find(e[1]);
            if(u!=v){
                p[u]=v;
                c--;
            }
        }
        return c-1;
    }
};