class Solution{
public:
    vector<int> pathExistenceQueries(int n,vector<int>&nums,int maxDiff,vector<vector<int>>&queries){
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)v.push_back({nums[i],i});
        sort(v.begin(),v.end());

        vector<int>pos(n),val(n);
        for(int i=0;i<n;i++){
            val[i]=v[i].first;
            pos[v[i].second]=i;
        }

        vector<int>nxt(n);
        int r=0;
        for(int l=0;l<n;l++){
            while(r+1<n&&val[r+1]-val[l]<=maxDiff)r++;
            nxt[l]=r;
        }

        int lg=0;
        while((1<<lg)<=n)lg++;
        vector<vector<int>>up(lg,vector<int>(n));
        for(int i=0;i<n;i++)up[0][i]=nxt[i];
        for(int k=1;k<lg;k++){
            for(int i=0;i<n;i++){
                up[k][i]=up[k-1][up[k-1][i]];
            }
        }

        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int a=pos[queries[i][0]];
            int b=pos[queries[i][1]];
            if(a>b)swap(a,b);
            if(a==b){
                ans.push_back(0);
                continue;
            }
            if(nxt[a]==a){
                ans.push_back(-1);
                continue;
            }
            int cur=a,res=0;
            for(int k=lg-1;k>=0;k--){
                if(up[k][cur]<b){
                    cur=up[k][cur];
                    res+=1<<k;
                }
            }
            if(nxt[cur]<b)ans.push_back(-1);
            else ans.push_back(res+1);
        }
        return ans;
    }
};