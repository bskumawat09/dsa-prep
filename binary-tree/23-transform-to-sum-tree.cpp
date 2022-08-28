/*
 * https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1
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
    // your code here
    void toSumTree(Node* root) {
        _sum(root);
    }

private:
    int _sum(Node* node) {
        if(node == NULL) return 0;

        int lsum = _sum(node->left);
        int rsum = _sum(node->right);

        int originalVal = node->data;
        node->data = lsum + rsum;

        return (originalVal + lsum + rsum);
    }
};

/*
Solution:
Time    = O(N)
Space   = O(H)
*/
