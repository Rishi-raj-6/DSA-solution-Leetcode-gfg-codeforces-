class Solution{
public:
    int getCount(long long n){
        int ans=0;
        for(long long len=2;len*(len+1)/2<=n;len++){
            long long rem=n-len*(len-1)/2;
            if(rem>0&&rem%len==0)ans++;
        }
        return ans;
    }
};