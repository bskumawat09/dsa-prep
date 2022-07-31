/*
 * https://practice.geeksforgeeks.org/problems/mirror-tree/1
 *
 */

class Solution {
public:
    void mirror(Node* node) {
        if(node == NULL)
            return;

        if(node->left == NULL && node->right == NULL)  // if leaf node
            return;

        mirror(node->left);   // mirror left subtree
        mirror(node->right);  // mirror right subtree

        // mirror current tree by swaping left and right pointers
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
};

/*
Time    = O(N)
Space   = O(H)
*/