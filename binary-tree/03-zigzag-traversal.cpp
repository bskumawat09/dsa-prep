/*
https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1
*/

class Solution {
public:
    vector<int> zigZagTraversal(Node* root) {
        // Code here
        vector<int> ans;

        int leftToRight = 1;
        stack<Node*> mstk;  // main stack
        stack<Node*> cstk;  // child stack
        mstk.push(root);

        while(mstk.size()) {
            Node* t = mstk.top();
            mstk.pop();

            ans.push_back(t->data);

            if(leftToRight) {
                if(t->left != NULL) cstk.push(t->left);
                if(t->right != NULL) cstk.push(t->right);
            } else {
                if(t->right != NULL) cstk.push(t->right);
                if(t->left != NULL) cstk.push(t->left);
            }
            if(mstk.empty()) {
                mstk = cstk;
                cstk = stack<Node*>();
                leftToRight ^= 1;
            }
        }
        return ans;
    }
};