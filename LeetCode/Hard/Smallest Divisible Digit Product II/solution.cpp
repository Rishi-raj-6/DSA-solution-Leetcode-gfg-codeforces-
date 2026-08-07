class Solution {
public:
    int ea[10] = {0,0,1,0,2,0,1,0,3,0};
    int eb[10] = {0,0,0,1,0,0,1,0,0,2};
    int ec[10] = {0,0,0,0,0,1,0,0,0,0};
    int ed[10] = {0,0,0,0,0,0,0,1,0,0};

    int minDigits(int a,int b,int c,int d){
        if(a<0)a=0;
        if(b<0)b=0;
        if(c<0)c=0;
        if(d<0)d=0;
        int best = INT_MAX;
        int kmax = min(a,b);
        for(int k=0;k<=kmax;k++){
            int ra=a-k, rb=b-k;
            int cost = k + (ra+2)/3 + (rb+1)/2;
            best = min(best,cost);
        }
        return best + c + d;
    }

    string construct(int ra,int rb,int rc,int rd,int L){
        string res(L,'1');
        for(int i=0;i<L;i++){
            for(int dg=1;dg<=9;dg++){
                int na=max(0,ra-ea[dg]), nb=max(0,rb-eb[dg]), nc=max(0,rc-ec[dg]), nd=max(0,rd-ed[dg]);
                if(minDigits(na,nb,nc,nd) <= L-i-1){
                    res[i]='0'+dg;
                    ra=na; rb=nb; rc=nc; rd=nd;
                    break;
                }
            }
        }
        return res;
    }

    string smallestNumber(string num, long long t) {
        long long tt=t;
        int a=0,b=0,c=0,d=0;
        while(tt%2==0){tt/=2;a++;}
        while(tt%3==0){tt/=3;b++;}
        while(tt%5==0){tt/=5;c++;}
        while(tt%7==0){tt/=7;d++;}
        if(tt!=1) return "-1";

        int n = num.size();
        vector<int> prefA(n+1,0),prefB(n+1,0),prefC(n+1,0),prefD(n+1,0);
        int firstZero = n;
        for(int i=0;i<n;i++){
            int dg = num[i]-'0';
            if(dg==0 && firstZero==n) firstZero=i;
            prefA[i+1]=prefA[i]+ea[dg];
            prefB[i+1]=prefB[i]+eb[dg];
            prefC[i+1]=prefC[i]+ec[dg];
            prefD[i+1]=prefD[i]+ed[dg];
        }

        if(firstZero==n && prefA[n]>=a && prefB[n]>=b && prefC[n]>=c && prefD[n]>=d){
            return num;
        }

        int limit = min(n-1, firstZero);
        for(int p=limit;p>=0;p--){
            int a0=prefA[p], b0=prefB[p], c0=prefC[p], d0=prefD[p];
            int start = num[p]-'0'+1;
            for(int e=start;e<=9;e++){
                int ca=a0+ea[e], cb=b0+eb[e], cc=c0+ec[e], cd=d0+ed[e];
                int ra=max(0,a-ca), rb=max(0,b-cb), rc=max(0,c-cc), rd=max(0,d-cd);
                int L=n-p-1;
                if(minDigits(ra,rb,rc,rd)<=L){
                    string suf = construct(ra,rb,rc,rd,L);
                    return num.substr(0,p) + string(1,'0'+e) + suf;
                }
            }
        }

        int targetLen = n+1;
        int mfull = minDigits(a,b,c,d);
        if(mfull>targetLen) targetLen=mfull;
        return construct(a,b,c,d,targetLen);
    }
};