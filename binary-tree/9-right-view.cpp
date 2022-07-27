/*
https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    vector<int> rightView(Node* root) {
        // Your code here
        vector<int> ans;

        if(root == NULL) return ans;

        queue<Node*> q;
        q.push(root);

        while(q.size()) {
            // take out 1st element of each level
            ans.push_back(q.front()->data);

            int n = q.size();
            for(int i = 0; i < n; i++) {
                Node* t = q.front();
                q.pop();

                if(t->right != NULL) q.push(t->right);
                if(t->left != NULL) q.push(t->left);
            }
        }
        return ans;
    }

    /* ----------Method-2: Using recursive preorder---------- */

    vector<int> rightView2(Node* root) {
        // Your Code here
        vector<int> ans;
        reversePreorder(root, ans, 0);
        return ans;
    }

    void reversePreorder(Node* node, vector<int>& ans, int level) {
        if(node == NULL) {
            return;
        }
        // ans.size() = 2 represents, we are looking to fill 1st element of level 2
        if(level == ans.size()) {
            ans.push_back(node->data);
        }
        reversePreorder(node->right, ans, level + 1);
        reversePreorder(node->left, ans, level + 1);
    }
};
