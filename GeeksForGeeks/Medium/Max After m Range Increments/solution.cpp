class Solution {
public:
    long long findMax(int n,vector<int>& a,vector<int>& b,vector<int>& k){
        vector<long long> diff(n+1);
        for(int i=0;i<a.size();i++){
            diff[a[i]]+=k[i];
            if(b[i]+1<n) diff[b[i]+1]-=k[i];
        }
        long long ans=0,cur=0;
        for(int i=0;i<n;i++){
            cur+=diff[i];
            ans=max(ans,cur);
        }
        return ans;
    }
};