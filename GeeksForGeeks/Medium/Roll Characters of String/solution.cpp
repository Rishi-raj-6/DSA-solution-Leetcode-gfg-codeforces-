class Solution {
public:
    string findRollOut(string s,vector<int>& roll) {
        int n=s.size();
        vector<int> cnt(n+1,0);
        for(int x:roll) {
            cnt[0]++;
            cnt[x]--;
        }
        int sum=0;
        for(int i=0;i<n;i++) {
            sum+=cnt[i];
            s[i]=char('a'+(s[i]-'a'+sum)%26);
        }
        return s;
    }
};
