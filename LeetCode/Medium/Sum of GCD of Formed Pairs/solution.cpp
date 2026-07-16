class Solution{
public:
    long long gcdSum(vector<int>&nums){
        int n=nums.size();
        vector<long long>pre;
        long long mx=0;
        for(int x:nums){
            mx=max(mx,1LL*x);
            pre.push_back(gcd((long long)x,mx));
        }
        sort(pre.begin(),pre.end());
        long long ans=0;
        int i=0,j=n-1;
        while(i<j){
            ans+=gcd(pre[i],pre[j]);
            i++;
            j--;
        }
        return ans;
    }
};