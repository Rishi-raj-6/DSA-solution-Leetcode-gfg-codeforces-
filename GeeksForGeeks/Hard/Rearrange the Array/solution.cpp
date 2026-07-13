class Solution{
public:
    int minOperations(vector<int>&a){
        const int mod=1000000007;
        int n=a.size();
        vector<int>vis(n,0),cnt(10001,0);

        for(int i=0;i<n;i++){
            if(vis[i])continue;
            int len=0,j=i;
            while(!vis[j]){
                vis[j]=1;
                j=a[j]-1;
                len++;
            }
            int x=len;
            for(int p=2;p*p<=x;p++){
                if(x%p==0){
                    int c=0;
                    while(x%p==0){
                        x/=p;
                        c++;
                    }
                    cnt[p]=max(cnt[p],c);
                }
            }
            if(x>1)cnt[x]=max(cnt[x],1);
        }

        long long ans=1;
        for(int p=2;p<=10000;p++){
            while(cnt[p]--){
                ans=ans*p%mod;
            }
        }
        return ans;
    }
};