class Solution{
public:
    int minimumEdgeReversal(vector<vector<int>>& edges,int n,int src,int dst){
        vector<vector<pair<int,int>>> g(n+1);
        for(auto &e:edges){
            int u=e[0],v=e[1];
            g[u].push_back({v,0});
            g[v].push_back({u,1});
        }
        deque<int> q;
        vector<int> d(n+1,1e9);
        d[src]=0;
        q.push_front(src);
        while(!q.empty()){
            int u=q.front();
            q.pop_front();
            for(auto [v,w]:g[u]){
                if(d[u]+w<d[v]){
                    d[v]=d[u]+w;
                    if(w==0)q.push_front(v);
                    else q.push_back(v);
                }
            }
        }
        return d[dst]==1e9?-1:d[dst];
    }
};