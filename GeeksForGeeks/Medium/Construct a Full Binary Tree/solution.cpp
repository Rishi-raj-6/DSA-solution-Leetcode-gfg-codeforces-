/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution{
public:
    unordered_map<int,int> mp;

    Node* solve(vector<int>& pre,vector<int>& mir,int &i,int l,int r){
        if(i>=pre.size()||l>r) return NULL;

        Node* root=new Node(pre[i++]);
        if(l==r||i>=pre.size()) return root;

        int k=mp[pre[i]];
        if(k<=r){
            root->left=solve(pre,mir,i,k,r);
            root->right=solve(pre,mir,i,l+1,k-1);
        }
        return root;
    }

    Node* constructBinaryTree(vector<int>& pre,vector<int>& preMirror){
        mp.clear();
        for(int i=0;i<preMirror.size();i++)
            mp[preMirror[i]]=i;
        int i=0;
        return solve(pre,preMirror,i,0,preMirror.size()-1);
    }
};