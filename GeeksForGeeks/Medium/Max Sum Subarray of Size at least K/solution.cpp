class Solution{
public:
    int maxSumWithK(vector<int>& arr,int k){
        int n=arr.size();
        vector<int> best(n);
        best[0]=arr[0];
        for(int i=1;i<n;i++)
            best[i]=max(arr[i],best[i-1]+arr[i]);
        int sum=0;
        for(int i=0;i<k;i++) sum+=arr[i];
        int ans=sum;
        for(int i=k;i<n;i++){
            sum+=arr[i]-arr[i-k];
            ans=max(ans,sum);
            ans=max(ans,sum+best[i-k]);
        }
        return ans;
    }
};