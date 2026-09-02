class Solution {
public:
    int solve(int n,string s) {
        set<char>in;
        set<char>rejected;
        int ans=0;
        for (char c:s) {
            if (rejected.count(c))
                continue;
            if (in.count(c)) {
                in.erase(c);
            }else if (in.size()<n) {
                in.insert(c);
            }else {
                rejected.insert(c);
                ans++;
            }
        }
        return ans;
    }
};