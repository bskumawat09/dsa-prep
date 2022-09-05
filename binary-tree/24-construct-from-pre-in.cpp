/*
 * https://practice.geeksforgeeks.org/problems/construct-tree-1/1
 *
 */

class Solution {
public:
    Node* buildTree(int pre[], int in[], int n) {
        Node* root = _buildTree(pre, in, 0, n - 1, 0, n - 1);
        return root;
    }

    Node* _buildTree(int pre[], int in[], int preStart, int preEnd, int inStart, int inEnd) {
        if(preStart > preEnd) return NULL;

        Node* root = new Node(pre[preStart]);

        // 1st element in preorder represents root. Find this root in inorder array,
        // all the elements left to it are part of left subtree and that are on right are part of right subtree
        int i = inStart;
        while(in[inStart] != pre[preStart]) i++;

        int cnt = i - inStart;  // count of no. of left subtree nodes for current root

        root->left = _buildTree(pre, in, preStart + 1, preStart + cnt, inStart, i - 1);
        root->right = _buildTree(pre, in, preStart + cnt + 1, preEnd, i + 1, inEnd);
    }
};

/*
Time    = O(N^2)
Space   = O(N)
*/
