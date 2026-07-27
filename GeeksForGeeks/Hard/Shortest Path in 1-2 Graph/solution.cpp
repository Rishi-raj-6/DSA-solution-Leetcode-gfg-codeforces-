class Solution {
public:
    int shortestPath(int V,int src,int dest,vector<vector<int>>& edges){
        vector<pair<int,int>> adj[V];
        for(auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }

        vector<int> dis(V,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        dis[src]=0;
        pq.push({0,src});

        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();

            int d=t.first,u=t.second;
            if(d>dis[u]) continue;

            for(auto x:adj[u]){
                int v=x.first,w=x.second;
                if(dis[v]>d+w){
                    dis[v]=d+w;
                    pq.push({dis[v],v});
                }
            }
        }

        return dis[dest]==1e9?-1:dis[dest];
    }
};