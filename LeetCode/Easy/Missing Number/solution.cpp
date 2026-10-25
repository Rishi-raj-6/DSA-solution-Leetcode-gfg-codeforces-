class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int a=0;
        for(int i=0;i<n+1;i++){
            a=a^i;
        }
        for(int x:nums){
            a=a^x;
        }
        return a;
        
    }
};