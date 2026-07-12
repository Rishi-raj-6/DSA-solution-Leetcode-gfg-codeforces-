class Solution{
public:
    vector<int> arrayRankTransform(vector<int>&arr){
        vector<int>v=arr;
        sort(v.begin(),v.end());
        unordered_map<int,int>mp;
        int rank=1;
        for(int i=0;i<v.size();i++){
            if(!mp.count(v[i])){
                mp[v[i]]=rank;
                rank++;
            }
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=mp[arr[i]];
        }
        return arr;
    }
};