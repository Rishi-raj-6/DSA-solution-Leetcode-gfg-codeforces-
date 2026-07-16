class Solution{
public:
    int maxDiffSubArrays(vector<int>&arr){
        int n=arr.size();
        vector<int>lmax(n),rmax(n),lmin(n),rmin(n);

        int cur=arr[0];
        lmax[0]=arr[0];
        for(int i=1;i<n;i++){
            cur=max(arr[i],cur+arr[i]);
            lmax[i]=max(lmax[i-1],cur);
        }

        cur=arr[n-1];
        rmax[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            cur=max(arr[i],cur+arr[i]);
            rmax[i]=max(rmax[i+1],cur);
        }

        cur=arr[0];
        lmin[0]=arr[0];
        for(int i=1;i<n;i++){
            cur=min(arr[i],cur+arr[i]);
            lmin[i]=min(lmin[i-1],cur);
        }

        cur=arr[n-1];
        rmin[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            cur=min(arr[i],cur+arr[i]);
            rmin[i]=min(rmin[i+1],cur);
        }

        int ans=0;
        for(int i=0;i<n-1;i++){
            ans=max(ans,abs(lmax[i]-rmin[i+1]));
            ans=max(ans,abs(lmin[i]-rmax[i+1]));
        }

        return ans;
    }
};