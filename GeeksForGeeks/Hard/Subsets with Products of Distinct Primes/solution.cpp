class Solution{
public:
    int countSubsets(vector<int>& arr){
        const int MOD=1e9+7;
        vector<int> cnt(31);
        for(int x:arr) cnt[x]++;
        vector<int> primes={2,3,5,7,11,13,17,19,23,29};
        vector<int> mask(31,-1);
        for(int i=2;i<=30;i++){
            int x=i,m=0;
            bool ok=true;
            for(int j=0;j<10;j++){
                int p=primes[j],c=0;
                while(x%p==0){
                    x/=p;
                    c++;
                }
                if(c>1){
                    ok=false;
                    break;
                }
                if(c)m|=1<<j;
            }
            if(ok) mask[i]=m;
        }
        vector<long long> dp(1<<10);
        dp[0]=1;
        for(int i=2;i<=30;i++){
            if(cnt[i]==0||mask[i]==-1) continue;
            for(int s=(1<<10)-1;s>=0;s--)
                if((s&mask[i])==0)
                    dp[s|mask[i]]=(dp[s|mask[i]]+dp[s]*cnt[i])%MOD;
        }
        long long ans=0;
        for(int s=1;s<(1<<10);s++)
            ans=(ans+dp[s])%MOD;
        long long mul=1;
        while(cnt[1]--)
            mul=mul*2%MOD;
        return ans*mul%MOD;
    }
};