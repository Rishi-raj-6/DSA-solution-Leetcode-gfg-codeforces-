class Solution{
public:
    int countMinOperations(vector<int>& arr){
        int ans=0;
        while(true){
            bool zero=true;
            for(int &x:arr){
                if(x&1){
                    x--;
                    ans++;
                }
                if(x) zero=false;
            }
            if(zero) break;
            for(int &x:arr) x/=2;
            ans++;
        }
        return ans;
    }
};
