class Solution{
public:
    int maxAmount(vector<int>&arr,int k){
        const long long mod=1000000007;
        priority_queue<long long>pq;
        for(int x:arr)pq.push(x);
        long long ans=0;
        while(k--&& !pq.empty()){
            long long x=pq.top();
            pq.pop();
            ans=(ans+x)%mod;
            if(x>1)pq.push(x-1);
        }
        return ans;
    }
};