class Solution{
public:
    int removeCoveredIntervals(vector<vector<int>>&intervals){
        sort(intervals.begin(),intervals.end(),[](auto&a,auto&b){
            if(a[0]==b[0])return a[1]>b[1];
            return a[0]<b[0];
        });
        int ans=0,end=0;
        for(auto &v:intervals){
            if(v[1]>end){
                ans++;
                end=v[1];
            }
        }
        return ans;
    }
};