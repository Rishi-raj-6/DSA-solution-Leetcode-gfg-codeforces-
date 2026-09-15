class Solution {
public:
    int dominantPairs(vector<int>& arr) {
        int n=arr.size();
        int mid=n/2;
        vector<int> first(arr.begin(), arr.begin()+mid);
        vector<int> second(arr.begin()+mid,arr.end());
        sort(first.begin(),first.end());
        sort(second.begin(),second.end());
        int i=0;
        int j=0;
        int ans=0;
        while (i<mid &&j<mid) {
            if (first[i]>=5*second[j]) {
                ans+=mid-i;
                j++;
            } else {
                i++;
            }
        }
        return ans;
    }
};