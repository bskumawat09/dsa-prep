/*
https://practice.geeksforgeeks.org/problems/vertical-width-of-a-binary-tree/1

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
    int verticalWidth(Node* root) {
        // Code here
        if(root == NULL) return 0;

        int min = 0;
        int max = 0;

        preorder(root, &min, &max, 0);
        return max - min + 1;
    }

    void preorder(Node* node, int* min, int* max, int hl) {
        if(node == NULL) return;

        if(hl > *max) {
            *max = hl;
        }
        if(hl < *min) {
            *min = hl;
        }
        preorder(node->left, min, max, hl - 1);
        preorder(node->right, min, max, hl + 1);
    }
};

/*
Time    = O(N)
Space   = O(H)
*/
