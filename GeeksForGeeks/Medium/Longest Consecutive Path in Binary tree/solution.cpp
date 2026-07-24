/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
public:
    int ans;

    void dfs(Node* root,int len,int prev) {
        if (!root)
            return;

        if (root->data==prev+1)
            len++;
        else
            len=1;

        ans=max(ans,len);

        dfs(root->left,len,root->data);
        dfs(root->right,len,root->data);
    }

    int longestConsecutive(Node* root) {
        ans=1;

        dfs(root,0,root->data-1);

        if (ans==1)
            return -1;

        return ans;
    }
};