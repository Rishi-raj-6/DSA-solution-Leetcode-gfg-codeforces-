class Solution {
public:
    vector<int> increasingNumbers(int n) {
        vector<int> ans;
        
        if (n == 1) {
            for (int i = 0; i <= 9; i++) ans.push_back(i);
            return ans;
        }
        
        if (n > 9) return ans;
        
        function<void(int, int, int)> solve = [&](int len, int last, int num) {
            if (len == n) {
                ans.push_back(num);
                return;
            }
            
            for (int d = last + 1; d <= 9; d++) {
                solve(len + 1, d, num * 10 + d);
            }
        };
        
        for (int start = 1; start <= 9; start++) {
            solve(1, start, start);
        }
        
        return ans;
    }
};