class Solution {
public:
    long long maxDiffSum(vector<int>& arr) 
    {
        long long a=0,b=0;
        for (int i=1;i<arr.size();i++) {
            long long x=max(a+abs(arr[i]-arr[i-1]),b+abs(arr[i]-1));
            long long y=max(a+abs(1-arr[i-1]),b);
            a=x;
            b=y;
        }
        return max(a,b);
    }
};