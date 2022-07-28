/**
 * https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
 * https://leetcode.com/problems/balanced-binary-tree/
 *
 */

class Pair {
public:
    int height;
    bool isBalanced;

    Pair(int height, bool isBalanced) {
        this->height = height;
        this->isBalanced = isBalanced;
    }
};

class Solution {
public:
    bool isBalanced(Node* root) {
        // code here
        Pair* p = helper(root);
        return p->isBalanced;
    }

    Pair* helper(Node* node) {
        if(node == NULL) {
            return new Pair(0, true);
        }

        Pair* lsp = helper(node->left);  // left subtree pair
        if(lsp->isBalanced == false) return lsp;

        Pair* rsp = helper(node->right);  // right subtree pair
        if(rsp->isBalanced == false) return rsp;

        // it require heights of left & right childs to check if tree is balance
        bool curIsBalance = abs(lsp->height - rsp->height) > 1 ? false : true;
        int curHeight = max(lsp->height, rsp->height) + 1;

        return new Pair(curHeight, curIsBalance);
    }
};

/* -----------Method-2: Return height & evaluate isBalanced----------- */

class Solution2 {
public:
    bool isBalanced(Node* root) {
        // code here
        bool isHeightBalanced = true;
        helper(root, &isHeightBalanced);
        return isHeightBalanced;
    }

    int helper(Node* root, bool* ihb) {
        if(root == NULL) return 0;

        int lsh = helper(root->left, ihb);   // left subtree height
        int rsh = helper(root->right, ihb);  // right subtree height

        if(abs(lsh - rsh) > 1) {
            *ihb = false;
        }
        return max(lsh, rsh) + 1;
    }
};
