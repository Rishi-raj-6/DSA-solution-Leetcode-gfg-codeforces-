
class Solution {
public:
    int maxSum(vector<int>& nums,int k) {
        const int mod=1e9+7;
        int cnt[31]={0};
        for(int x:nums) {
            for(int i=0;i<31;i++) {
                if(x&(1<<i)) cnt[i]++;
            }
        }
        long long ans=0;
        for(int i=0;i<k;i++) {
            long long x=0;
            for(int j=0;j<31;j++) {
                if(cnt[j]>0) {
                    x|=(1LL<<j);
                    cnt[j]--;
                }
            }
            ans=(ans+x*x)%mod;
        }
        return ans;
    }
};
