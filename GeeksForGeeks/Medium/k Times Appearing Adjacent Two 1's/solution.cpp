class Solution{
public:
    int countStrings(int n,int k){
        const int mod=1000000007;
        vector<int>dp0(k+2),dp1(k+2),ndp0(k+2),ndp1(k+2);
        dp0[0]=1;
        dp1[0]=1;
        for(int i=2;i<=n;i++){
            fill(ndp0.begin(),ndp0.end(),0);
            fill(ndp1.begin(),ndp1.end(),0);
            for(int j=0;j<=k;j++){
                ndp0[j]=(ndp0[j]+dp0[j])%mod;
                ndp0[j]=(ndp0[j]+dp1[j])%mod;
                ndp1[j]=(ndp1[j]+dp0[j])%mod;
                if(j<k)ndp1[j+1]=(ndp1[j+1]+dp1[j])%mod;
            }
            dp0=ndp0;
            dp1=ndp1;
        }
        return (dp0[k]+dp1[k])%mod;
    }
};