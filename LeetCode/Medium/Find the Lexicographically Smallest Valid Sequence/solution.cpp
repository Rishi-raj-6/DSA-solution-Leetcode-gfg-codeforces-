class Solution{
public:
    vector<int> validSequence(string word1,string word2){
        int n=word1.size(),m=word2.size();
        vector<int> suf(n+1,m);
        for(int i=n-1,j=m-1;i>=0;i--){
            if(j>=0&&word1[i]==word2[j]) j--;
            suf[i]=j+1;
        }

        vector<int> ans;
        int j=0,used=0;

        for(int i=0;i<n&&j<m;i++){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }
            else if(!used&&(m-suf[i+1])+j+1>=m){
                ans.push_back(i);
                j++;
                used=1;
            }
        }

        if(j<m) return {};
        return ans;
    }
};