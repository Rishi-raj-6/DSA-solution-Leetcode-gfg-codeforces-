class Solution{
public:
    int maxSumSubarray(vector<int>&arr){
        int n=arr.size();
        vector<int>f(n),b(n);
        f[0]=arr[0];
        for(int i=1;i<n;i++)f[i]=max(arr[i],f[i-1]+arr[i]);
        b[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)b[i]=max(arr[i],b[i+1]+arr[i]);
        int ans=*max_element(f.begin(),f.end());
        for(int i=1;i<n-1;i++)ans=max(ans,f[i-1]+b[i+1]);
        return ans;
    }
};