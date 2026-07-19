class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);
        vector<bool> vis(26);

        for (int j = 0; j < s.size(); j++)
            last[s[j] - 'a'] = j;

        string st;

        for (int j = 0; j < s.size(); j++) {
            int x = s[j] - 'a';
            if (vis[x]) continue;

            while (!st.empty() && st.back() > s[j] && last[st.back() - 'a'] > j) {
                vis[st.back() - 'a'] = 0;
                st.pop_back();
            }

            st.push_back(s[j]);
            vis[x] = 1;
        }

        return st;
    }
};