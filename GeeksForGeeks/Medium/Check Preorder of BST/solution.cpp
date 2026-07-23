class Solution {
public:
    bool canRepresentBST(vector<int> &arr) {
        stack<int> st;
        int low=INT_MIN;

        for (int x:arr) {
            if (x<low)
                return false;

            while (!st.empty()&&x>st.top()) {
                low=st.top();
                st.pop();
            }

            st.push(x);
        }

        return true;
    }
};