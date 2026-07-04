class Solution{
public:
    struct BIT{
        int n;
        vector<int>bit;
        BIT(int sz){
            n=sz;
            bit.assign(n+1,0);
        }
        void update(int i){
            while(i<=n){
                bit[i]++;
                i+=i&-i;
            }
        }
        int query(int i){
            int s=0;
            while(i>0){
                s+=bit[i];
                i-=i&-i;
            }
            return s;
        }
    };

    long long countSubstring(string s){
        int n=s.size();
        vector<int>pre(n+1,0),v;
        v.push_back(0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+(s[i]=='1'?1:-1);
            v.push_back(pre[i+1]);
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());

        BIT ft(v.size());
        long long ans=0;

        for(int x:pre){
            int id=lower_bound(v.begin(),v.end(),x)-v.begin()+1;
            ans+=ft.query(id-1);
            ft.update(id);
        }

        return ans;
    }
};