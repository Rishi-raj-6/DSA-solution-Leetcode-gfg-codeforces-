
class Solution {
public:
    int minOperations(vector<int>& nums){
        int n=nums.size(),ans=INT_MAX;
        bool a=true,b=true;

        for(int i=0;i<n;i++){
            if(nums[i]!=(nums[0]+i)%n)a=false;
            if(nums[i]!=(nums[0]-i+n)%n)b=false;
        }

        if(a){
            int k=nums[0];
            ans=min(ans,(n-k)%n);
            if(k>0)ans=min(ans,k+2);
        }

        if(b){
            int k=nums[0];
            ans=min(ans,1+(k+1)%n);
            ans=min(ans,1+(n-1-k+n)%n);
        }

        return ans==INT_MAX?-1:ans;
    }
};
