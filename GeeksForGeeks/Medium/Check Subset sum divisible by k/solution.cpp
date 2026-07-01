class Solution{
public:
    bool divisibleByK(vector<int>&arr,int k){
        vector<int>dp(k,0),ndp;
        for(int x:arr){
            ndp=dp;
            ndp[x%k]=1;
            for(int r=0;r<k;r++){
                if(dp[r])ndp[(r+x)%k]=1;
            }
            dp=ndp;
            if(dp[0])return true;
        }
        return false;
    }
};