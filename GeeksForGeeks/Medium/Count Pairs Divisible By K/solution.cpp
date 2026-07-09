class Solution{
public:
    long long countKdivPairs(vector<int>&arr,int k){
        vector<long long>freq(k,0);
        long long ans=0;
        for(int i=0;i<arr.size();i++){
            int r=arr[i]%k;
            int need=(k-r)%k;
            ans+=freq[need];
            freq[r]++;
        }
        return ans;
    }
};