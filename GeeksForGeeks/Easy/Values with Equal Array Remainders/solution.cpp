class Solution {
public:
    int sameMod(vector<int>& a) {
        int g=0;
        for(int i=1;i<a.size();i++)
            g=__gcd(g,abs(a[i]-a[0]));
        if(g==0) return -1;
        int ans=0;
        for(int i=1;i*i<=g;i++){
            if(g%i==0){
                ans++;
                if(i!=g/i)
                    ans++;
            }
        }
        return ans;
    }
};