/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
public:
    int getCount(Node* r,int k) {
        vector<int> a;
        queue<pair<Node*,int>> q;
        q.push({r,1});
        while(!q.empty()){
            auto [u,d]=q.front();
            q.pop();
            if(!u->left&&!u->right)
                a.push_back(d);
            if(u->left)
                q.push({u->left,d+1});
            if(u->right)
                q.push({u->right,d+1});
        }
        sort(a.begin(),a.end());
        int ans=0;
        for(int x:a){
            if(k<x) break;
            k-=x;
            ans++;
        }
        return ans;
    }
};