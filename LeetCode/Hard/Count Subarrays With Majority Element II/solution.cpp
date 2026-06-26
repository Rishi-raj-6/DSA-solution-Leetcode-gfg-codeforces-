class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + (nums[i] == target ? 1 : -1);

        vector<int> sorted_pre = pre;
        sort(sorted_pre.begin(), sorted_pre.end());
        sorted_pre.erase(unique(sorted_pre.begin(), sorted_pre.end()), sorted_pre.end());
        int m = sorted_pre.size();

        auto getIdx = [&](int v) {
            return lower_bound(sorted_pre.begin(), sorted_pre.end(), v) - sorted_pre.begin() + 1;
        };

        vector<int> bit(m + 2, 0);
        auto update = [&](int i) {
            for (; i <= m; i += i & -i) bit[i]++;
        };
        auto query = [&](int i) {
            int s = 0;
            for (; i > 0; i -= i & -i) s += bit[i];
            return s;
        };

        long long ans = 0;
        for (int i = 0; i <= n; i++) {
            int idx = getIdx(pre[i]);
            ans += query(idx - 1);
            update(idx);
        }
        return ans;
    }
};