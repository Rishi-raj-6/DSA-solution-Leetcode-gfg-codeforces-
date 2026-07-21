class Solution {
public:
    int maxIndexDifference(string& s) {
        int n=s.size();
        vector<int> mx(26,-1);
        int ans=-1;
        for (int j=n-1;j>=0;j--) {
            int x=s[j]-'a';
            int best=j;
            if (x<25&&mx[x+1]!=-1)
                best=mx[x+1];
            mx[x]=max(mx[x],best);
            if (x==0)
                ans=max(ans,best-j);
        }
        return ans;
    }
};