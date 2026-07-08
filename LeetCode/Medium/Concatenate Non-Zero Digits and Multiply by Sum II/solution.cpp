class Solution{
public:
    static const int mod=1000000007;

    struct Node{
        long long val;
        int len;
        long long sum;
    };

    vector<Node>st;
    vector<long long>pw;

    Node merge(Node a,Node b){
        return {(a.val*pw[b.len]+b.val)%mod,a.len+b.len,a.sum+b.sum};
    }

    void build(int p,int l,int r,string&s){
        if(l==r){
            if(s[l]=='0')st[p]={0,0,0};
            else st[p]={s[l]-'0',1,s[l]-'0'};
            return;
        }
        int m=(l+r)/2;
        build(p<<1,l,m,s);
        build(p<<1|1,m+1,r,s);
        st[p]=merge(st[p<<1],st[p<<1|1]);
    }

    Node query(int p,int l,int r,int i,int j){
        if(i<=l&&r<=j)return st[p];
        int m=(l+r)/2;
        if(j<=m)return query(p<<1,l,m,i,j);
        if(i>m)return query(p<<1|1,m+1,r,i,j);
        return merge(query(p<<1,l,m,i,j),query(p<<1|1,m+1,r,i,j));
    }

    vector<int> sumAndMultiply(string s,vector<vector<int>>&queries){
        int n=s.size();
        pw.assign(n+1,1);
        for(int i=1;i<=n;i++)pw[i]=pw[i-1]*10%mod;
        st.assign(4*n,{0,0,0});
        build(1,0,n-1,s);
        vector<int>ans;
        for(auto &q:queries){
            Node cur=query(1,0,n-1,q[0],q[1]);
            ans.push_back(cur.val*(cur.sum%mod)%mod);
        }
        return ans;
    }
};