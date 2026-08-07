class Solution{
public:
    long long countFriendsPairings(int n){
        if(n<=2) return n;
        long long a=1,b=2,c;
        for(int i=3;i<=n;i++){
            c=b+(i-1)*a;
            a=b;
            b=c;
        }
        return b;
    }
};