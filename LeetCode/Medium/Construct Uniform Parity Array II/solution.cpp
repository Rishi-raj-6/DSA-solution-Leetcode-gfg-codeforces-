class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd=INT_MAX;
        for (int x:nums1) {
            if (x%2)
                odd=min(odd, x);
        }
        if (odd==INT_MAX)
            return true;
        for (int x:nums1) {
            if (x%2==0&&x<odd)
                return false;
        }
        return true;
    }
};