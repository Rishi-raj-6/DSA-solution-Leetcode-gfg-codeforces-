class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size(),l=0,s=0,ans=1e9;
        vector<int> dp(n+1,1e9);
        for(int r=0;r<n;r++){
            s+=arr[r];
            while(s>target)s-=arr[l++];
            if(r>0)dp[r+1]=dp[r];
            if(s==target){
                int len=r-l+1;
                if(dp[l]!=1e9)ans=min(ans,len+dp[l]);
                dp[r+1]=min(dp[r+1],len);
            }
        }
        return ans==1e9?-1:ans;
    }
};