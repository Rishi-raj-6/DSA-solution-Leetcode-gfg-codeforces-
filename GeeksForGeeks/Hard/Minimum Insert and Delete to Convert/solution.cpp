class Solution{
public:
    int minInsAndDel(vector<int>&a,vector<int>&b){
        unordered_map<int,int>mp;
        for(int i=0;i<b.size();i++)mp[b[i]]=i;
        vector<int>v;
        for(int x:a){
            if(mp.count(x))v.push_back(mp[x]);
        }
        vector<int>lis;
        for(int x:v){
            auto it=lower_bound(lis.begin(),lis.end(),x);
            if(it==lis.end())lis.push_back(x);
            else *it=x;
        }
        int lcs=lis.size();
        return a.size()+b.size()-2*lcs;
    }
};