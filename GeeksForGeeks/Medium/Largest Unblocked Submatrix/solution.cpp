class Solution{
public:
    int largestArea(int n,int m,vector<vector<int>>&arr){
        vector<int>rows,cols;
        for(auto &x:arr){
            rows.push_back(x[0]);
            cols.push_back(x[1]);
        }
        sort(rows.begin(),rows.end());
        sort(cols.begin(),cols.end());
        int mxr=0,mxc=0,pre=0;
        for(int x:rows){
            mxr=max(mxr,x-pre-1);
            pre=x;
        }
        mxr=max(mxr,n-pre);
        pre=0;
        for(int x:cols){
            mxc=max(mxc,x-pre-1);
            pre=x;
        }
        mxc=max(mxc,m-pre);
        return mxr*mxc;
    }
};