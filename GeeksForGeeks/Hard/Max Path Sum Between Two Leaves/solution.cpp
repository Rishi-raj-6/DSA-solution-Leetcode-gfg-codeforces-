/* Node Structure
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = nullptr;
        right = nullptr;
    }
}
*/

class Solution {
public:
    int ans;
    int solve(Node* root) {
        if(!root) return 0;
        if(!root->left && !root->right)
            return root->data;
        int l = solve(root->left);
        int r = solve(root->right);
        if(root->left && root->right) {
            ans = max(ans, l + r + root->data);
            return root->data + max(l, r);
        }
        if(root->left)
            return root->data + l;
        return root->data + r;
    }
    int maxPathSum(Node* root) {
        if(!root) return -1;
        ans = INT_MIN;
        solve(root);
        if(ans == INT_MIN)
            return -1;
        return ans;
    }
};