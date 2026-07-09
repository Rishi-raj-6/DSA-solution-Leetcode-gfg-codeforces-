class Solution{
public:
    vector<int>par;

    int find(int x){
        if(par[x]==x)return x;
        return par[x]=find(par[x]);
    }

    void unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a!=b)par[a]=b;
    }

    vector<bool> pathExistenceQueries(int n,vector<int>&nums,int maxDiff,vector<vector<int>>&queries){
        par.resize(n);
        for(int i=0;i<n;i++)par[i]=i;

        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<=maxDiff){
                unite(i,i-1);
            }
        }

        vector<bool>ans;
        for(int i=0;i<queries.size();i++){
            ans.push_back(find(queries[i][0])==find(queries[i][1]));
        }
        return ans;
    }
};