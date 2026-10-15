class Solution {
public:
    int maxValue(int n) {
        int cnt = 0;
        for(int i = 30; i >= 0; i--) {
            if(n & (1 << i)) {
                cnt++;
                if(cnt == 3) {
                    n = n & ~(1 << i);
                    cnt = 0;
                }
            } else {
                cnt = 0;
            }
        }
        return n;
    }
};
