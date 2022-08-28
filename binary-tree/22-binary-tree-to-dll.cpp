/*
 * https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1
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
    Node* treeToDLL(Node* root) {
        Node* head = new Node(-1);
        prev = head;

        _inorder(root);

        Node* temp = head;

        head = head->right;
        head->left = NULL;

        free(temp);

        return head;
    }

private:
    Node* prev = NULL;

    void _inorder(Node* node) {
        if(node == NULL) return;

        _inorder(node->left);

        // in inorder of every node, link the current node to a node visited just before the current node, in inorder traversal
        prev->right = node;
        node->left = prev;
        prev = node;

        _inorder(node->right);
    }
};

/*
Solution:
Time    = O(N)
Space   = O(H)
*/
