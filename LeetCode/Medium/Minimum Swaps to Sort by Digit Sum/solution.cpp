
class Solution {
public:
    int digitSum(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums){
        int n=nums.size();
        vector<pair<int,int>> a;

        for(int i=0;i<n;i++){
            a.push_back({digitSum(nums[i]),nums[i]});
        }

        sort(a.begin(),a.end());

        unordered_map<int,int> pos;
        for(int i=0;i<n;i++){
            pos[nums[i]]=i;
        }

        vector<bool> vis(n,false);
        int ans=0;

        for(int i=0;i<n;i++){
            if(vis[i])continue;

            int j=i,cnt=0;
            while(!vis[j]){
                vis[j]=true;
                j=pos[a[j].second];
                cnt++;
            }
            ans+=cnt-1;
        }
        return ans;
    }
};
