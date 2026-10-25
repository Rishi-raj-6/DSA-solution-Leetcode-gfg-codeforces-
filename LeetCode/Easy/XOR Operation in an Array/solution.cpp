class Solution {
public:
    int xorOperation(int n, int start) {
        // int nums=nums[n];
        // n=nums.size();
        int a=0;
        for (int i=0;i<n;i++){
            a^=(start+2*i);
        }
        return a;
    }
};