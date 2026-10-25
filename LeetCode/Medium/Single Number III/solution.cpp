class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int a=0;
        for(int i:nums){
            a^=static_cast<unsigned int>(i);}
            unsigned int m=a&(-a);
            int x=0, y=0;
            for (int i:nums){
                if(static_cast<unsigned int>(i)&m)
            x^=i;
        else
            y^=i;
            }
        
        return {x,y};
    }
};