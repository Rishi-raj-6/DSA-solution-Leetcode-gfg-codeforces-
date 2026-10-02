class Solution{
public:
    string lexiString(string s){
        int n=s.size(),i=0,j=1,k=0;
        string a=s+s;
        while(i<n&&j<n&&k<n){
            if(a[i+k]==a[j+k]) k++;
            else{
                if(a[i+k]>a[j+k]) i=i+k+1;
                else j=j+k+1;
                if(i==j) j++;
                k=0;
            }
        }
        int p=min(i,j);
        return a.substr(p,n);
    }
};