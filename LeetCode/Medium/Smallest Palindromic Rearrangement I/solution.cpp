class Solution {
public:
    string smallestPalindrome(string s){
        vector<int> cnt(26);
        for(char c:s) cnt[c-'a']++;
        string left="",mid="";
        for(int i=0;i<26;i++){
            left+=string(cnt[i]/2,char(i+'a'));
            if(cnt[i]%2) mid=char(i+'a');
        }
        string right=left;
        reverse(right.begin(),right.end());
        return left+mid+right;
    }
};