class Solution{
public:
    int maxSubsetXOR(vector<int>& arr){
        int n=arr.size(),idx=0;
        for(int b=20;b>=0;b--){
            int i=idx;
            while(i<n&&((arr[i]>>b)&1)==0) i++;
            if(i==n) continue;
            swap(arr[idx],arr[i]);
            for(i=0;i<n;i++)
                if(i!=idx&&((arr[i]>>b)&1))
                    arr[i]^=arr[idx];
            idx++;
        }
        int ans=0;
        for(int x:arr) ans=max(ans,ans^x);
        return ans;
    }
};