class Solution {
public:
    int totalNumbers(vector<int>& d) {
        set<int> s;
        for(int i=0;i<d.size();i++){
            if(d[i]==0) continue;
            for(int j=0;j<d.size();j++){
                if(j==i) continue;
                for(int k=0;k<d.size();k++){
                    if(k==i||k==j) continue;
                    if(d[k]%2==0)
                        s.insert(d[i]*100+d[j]*10+d[k]);
                }
            }
        }
        return s.size();
    }
};