/*
 * https://practice.geeksforgeeks.org/problems/sum-tree/1
 *
 */

class Pair {
public:
    bool isSumTree;
    int sum;

    Pair(bool isSumTree, int sum) {
        this->isSumTree = isSumTree;
        this->sum = sum;
    }
};

class Solution {
public:
    bool isSumTree(Node* root) {
        Pair* ans = helper(root);
        return ans->isSumTree;
    }

    Pair* helper(Node* node) {
        if(node == NULL)
            return new Pair(true, 0);

        // leaf node is considered as sumTree
        if(node->left == NULL && node->right == NULL)
            return new Pair(true, node->data);

        Pair* lsp = helper(node->left);
        // if left subtree is not sumTree
        if(lsp->isSumTree == false) return lsp;

        Pair* rsp = helper(node->right);
        // if right subtree is not sumTree
        if(rsp->isSumTree == false) return rsp;

        bool curIsSumTree = (lsp->sum + rsp->sum == node->data) ? true : false;
        int curSum = (lsp->sum + rsp->sum) + node->data;

        return new Pair(curIsSumTree, curSum);
    }
};

/*
Time    = O(N)
Space   = O(N)
*/