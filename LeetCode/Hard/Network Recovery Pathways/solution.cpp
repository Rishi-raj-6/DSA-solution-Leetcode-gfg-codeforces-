class Solution{
public:
    bool check(long long x,vector<vector<pair<int,int>>>&g,vector<int>&indeg,vector<bool>&online,long long k){
        int n=online.size();
        vector<long long>dp(n,4e18);
        queue<int>q;
        vector<int>in=indeg;
        for(int i=0;i<n;i++)if(in[i]==0)q.push(i);
        dp[0]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto &[v,w]:g[u]){
                if((v==n-1||online[v])&&w>=x&&dp[u]!=4e18)
                    dp[v]=min(dp[v],dp[u]+w);
                if(--in[v]==0)q.push(v);
            }
        }
        return dp[n-1]<=k;
    }

    int findMaxPathScore(vector<vector<int>>&edges,vector<bool>&online,long long k){
        int n=online.size();
        vector<vector<pair<int,int>>>g(n);
        vector<int>indeg(n);
        long long hi=0;
        for(auto &e:edges){
            g[e[0]].push_back({e[1],e[2]});
            indeg[e[1]]++;
            hi=max(hi,1LL*e[2]);
        }
        long long lo=0,ans=-1;
        while(lo<=hi){
            long long mid=(lo+hi)/2;
            if(check(mid,g,indeg,online,k)){
                ans=mid;
                lo=mid+1;
            }else hi=mid-1;
        }
        return ans;
    }
};