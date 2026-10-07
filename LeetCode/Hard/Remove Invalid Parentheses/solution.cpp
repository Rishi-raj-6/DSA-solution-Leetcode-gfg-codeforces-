class Solution {
public:
    bool valid(string s) {
        int c = 0;
        for(char x : s) {
            if(x == '(') c++;
            else if(x == ')') {
                c--;
                if(c < 0) return false;
            }
        }
        return c == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> vis;
        queue<string> q;
        q.push(s);
        vis.insert(s);
        bool found = false;
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                string cur = q.front();
                q.pop();
                if(valid(cur)) {
                    ans.push_back(cur);
                   found = true;
                }
                if(found) continue;
                for(int i = 0; i < cur.size(); i++) {
                    if(cur[i] != '(' && cur[i] != ')')
                        continue;
                    string next = cur.substr(0, i) + cur.substr(i + 1);
                    if(vis.find(next) == vis.end()) {
                        vis.insert(next);
                        q.push(next);
                    }
                }
            }
            if(found) break;
        }
        return ans;
    }
};