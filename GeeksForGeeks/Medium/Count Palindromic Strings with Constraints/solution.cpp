class Solution {
  public:
      int palindromicStrings(int n,int k) {
          long long mod=1000000007;
          long long ans=0,p=1;
          for (int l=1;l<=n;l++) {
              int h=l/2;
              if (l>1&&l%2==0)
                p=p*(k-h+1)%mod;
              if (l%2==0)
                  ans=(ans+p)%mod;
              else
                  ans=(ans+p*(k-h))%mod;
          }
          return ans;
      }
  };