class Solution {
public:
    int minInsertions(string s) {
        int ans=0,n=0;
        for(char c:s) {
            if(c=='(') {
                n+=2;
                if(n%2) {
                    ans++;
                    n--;
                }
            }
            else {
                n--;
                if(n<0) {
                    ans++;
                    n=1;
                }
            }
        }
        return ans+n;
    }
};