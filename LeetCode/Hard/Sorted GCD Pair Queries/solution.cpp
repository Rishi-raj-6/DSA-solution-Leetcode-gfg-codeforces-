class Solution{
public:
    vector<int> gcdValues(vector<int>&nums,vector<long long>&queries){
        int mx=*max_element(nums.begin(),nums.end());
        vector<long long>freq(mx+1),cnt(mx+1),exact(mx+1);

        for(int x:nums)freq[x]++;

        for(int i=1;i<=mx;i++){
            for(int j=i;j<=mx;j+=i){
                cnt[i]+=freq[j];
            }
        }

        for(int i=mx;i>=1;i--){
            exact[i]=cnt[i]*(cnt[i]-1)/2;
            for(int j=i+i;j<=mx;j+=i){
                exact[i]-=exact[j];
            }
        }

        vector<long long>pref(mx+1);
        for(int i=1;i<=mx;i++)pref[i]=pref[i-1]+exact[i];

        vector<int>ans;
        for(long long q:queries){
            int l=1,r=mx,res=mx;
            while(l<=r){
                int mid=(l+r)/2;
                if(pref[mid]>q){
                    res=mid;
                    r=mid-1;
                }else l=mid+1;
            }
            ans.push_back(res);
        }
        return ans;
    }
};