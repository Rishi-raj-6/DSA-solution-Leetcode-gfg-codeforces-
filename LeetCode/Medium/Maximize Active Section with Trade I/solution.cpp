class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t="1"+s+"1";
        int one=0;
        for (char ch:s) {
            if (ch=='1')
                one++;
        }
        vector<pair<char,int>> runs;
        for (char ch:t) {
            if (runs.empty()||runs.back().first!=ch)
                runs.push_back({ch,1});
            else
                runs.back().second++;
        }
        int add=0;
        for (int j=1;j+1<runs.size();j++) {
            if (runs[j].first=='1'&&runs[j-1].first=='0'&&runs[j+1].first=='0')
                add=max(add,runs[j-1].second+runs[j+1].second);
        }
        return one+add;
    }
};