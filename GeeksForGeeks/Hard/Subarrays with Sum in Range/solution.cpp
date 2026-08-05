class Solution{
public:
    long long solve(vector<int>& arr,long long x){
        long long ans=0,sum=0;
        int j=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            while(sum>x){
                sum-=arr[j++];
            }
            ans+=i-j+1;
        }
        return ans;
    }

    long long countSubarray(vector<int>& arr,int l,int r){
        return solve(arr,r)-solve(arr,l-1);
    }
};