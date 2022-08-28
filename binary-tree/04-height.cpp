/*
https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

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
    int height(Node* node) {
        // code here
        if(node == NULL) return 0;

        int lh = height(node->left);
        int rh = height(node->right);

        return max(lh, rh) + 1;
    }
};

/*
Time    = O(N)
Space   = O(H)
*/
