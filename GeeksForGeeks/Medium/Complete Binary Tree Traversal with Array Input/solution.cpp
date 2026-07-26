class Solution {
public:
    vector<vector<int>> levelSort(vector<int>& arr){
        vector<vector<int>> ans;
        int i=0,n=arr.size(),cnt=1;
        while(i<n){
            vector<int> v;
            for(int j=0;j<cnt&&i<n;j++)
                v.push_back(arr[i++]);
            sort(v.begin(),v.end());
            ans.push_back(v);
            cnt*=2;
        }
        return ans;
    }
};