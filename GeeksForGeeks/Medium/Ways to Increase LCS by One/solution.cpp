class Solution{
public:
    int waysToIncreaseLCSBy1(string s1,string s2){
        int n=s1.size(),m=s2.size();
        vector<vector<int>>pre(n+1,vector<int>(m+1,0));
        vector<vector<int>>suf(n+2,vector<int>(m+2,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])pre[i][j]=pre[i-1][j-1]+1;
                else pre[i][j]=max(pre[i-1][j],pre[i][j-1]);
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s1[i]==s2[j])suf[i][j]=suf[i+1][j+1]+1;
                else suf[i][j]=max(suf[i+1][j],suf[i][j+1]);
            }
        }
        int lcs=pre[n][m],ans=0;
        for(int pos=0;pos<=n;pos++){
            vector<int>used(26,0);
            for(int j=0;j<m;j++){
                int c=s2[j]-'a';
                if(!used[c]&&pre[pos][j]+1+suf[pos][j+1]==lcs+1){
                    used[c]=1;
                    ans++;
                }
            }
        }
        return ans;
    }
};