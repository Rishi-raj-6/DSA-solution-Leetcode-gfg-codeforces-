class TrieNode {
public:
    TrieNode* child[26];
    int cnt;

    TrieNode() {
        cnt = 0;
        for (int j = 0; j < 26; j++)
            child[j] = NULL;
    }
};

class Solution {
public:
    vector<string> findPrefixes(vector<string>& arr) {
        TrieNode* root = new TrieNode();

        for (string &s : arr) {
            TrieNode* node = root;
            for (char ch : s) {
                int x = ch - 'a';
                if (!node->child[x])
                    node->child[x] = new TrieNode();
                node = node->child[x];
                node->cnt++;
            }
        }

        vector<string> ans;

        for (string &s : arr) {
            TrieNode* node = root;
            string cur;
            for (char ch : s) {
                int x = ch - 'a';
                node = node->child[x];
                cur.push_back(ch);
                if (node->cnt == 1)
                    break;
            }
            ans.push_back(cur);
        }

        return ans;
    }
};