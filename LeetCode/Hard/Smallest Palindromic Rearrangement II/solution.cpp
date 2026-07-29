class Solution {
public:
    const long long LIM=1000001;

    long long nCr(int n,int r){
        r=min(r,n-r);
        long long ans=1;
        for(int i=1;i<=r;i++){
            ans=ans*(n-i+1)/i;
            if(ans>=LIM) return LIM;
        }
        return ans;
    }

    long long ways(vector<int>& cnt){
        int tot=0;
        for(int x:cnt) tot+=x;

        long long ans=1;
        for(int x:cnt){
            if(x){
                ans*=nCr(tot,x);
                if(ans>=LIM) return LIM;
                tot-=x;
            }
        }
        return ans;
    }

    string smallestPalindrome(string s,int k){
        vector<int> cnt(26);
        for(char c:s) cnt[c-'a']++;

        string mid="";
        for(int i=0;i<26;i++){
            if(cnt[i]&1) mid=char(i+'a');
            cnt[i]/=2;
        }

        if(ways(cnt)<k) return "";

        int len=0;
        for(int x:cnt) len+=x;

        string left="";
        for(int i=0;i<len;i++){
            for(int c=0;c<26;c++){
                if(cnt[c]==0) continue;
                cnt[c]--;
                long long cur=ways(cnt);
                if(cur>=k){
                    left.push_back(char(c+'a'));
                    break;
                }
                k-=cur;
                cnt[c]++;
            }
        }

        string right=left;
        reverse(right.begin(),right.end());
        return left+mid+right;
    }
};