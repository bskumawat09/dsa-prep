/*
 * https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
 *
 * struct Node {
 *     int data;
 *     struct Node* left;
 *     struct Node* right;
 *
 *     Node(int x) {
 *         data = x;
 *         left = right = NULL;
 *     }
 * };
 */

class Solution {
public:
    vector<int> boundaryTraversal(Node* root) {
        // Code here
        vector<int> ans;
        ans.push_back(root->data);

        if(isLeaf(root)) return ans;  // if there is a single node in tree

        leftBoundary(root, ans);
        leaves(root, ans);
        rightBoundary(root, ans);

        return ans;
    }

private:
    bool isLeaf(Node* node) {
        if(node->left == NULL && node->right == NULL)
            return true;
        return false;
    }

    // add left boundary nodes
    void leftBoundary(Node* root, vector<int>& ans) {
        Node* cur = root->left;

        while(cur != NULL) {
            if(!isLeaf(cur))
                ans.push_back(cur->data);
            if(cur->left != NULL)
                cur = cur->left;
            else
                cur = cur->right;
        }
    }

    // add right boundary nodes in reverse order
    void rightBoundary(Node* root, vector<int>& ans) {
        stack<int> stk;
        Node* cur = root->right;

        while(cur != NULL) {
            if(!isLeaf(cur))
                stk.push(cur->data);
            if(cur->right != NULL)
                cur = cur->right;
            else
                cur = cur->left;
        }

        while(stk.size()) {
            ans.push_back(stk.top());
            stk.pop();
        }
    }

    // add leaf nodes
    void leaves(Node* node, vector<int>& ans) {
        if(isLeaf(node))
            ans.push_back(node->data);

        if(node->left != NULL)
            leaves(node->left, ans);

        if(node->right != NULL)
            leaves(node->right, ans);
    }
};

/*
Time    = O(H) + O(N) + O(H) => O(N)
Space   = O(N)
*/
