/*
https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

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
    int diameter(Node* root) {
        // Your code here
        int d = 0;

        helper(root, &d);
        return d;
    }

    int helper(Node* node, int* d) {
        if(node == NULL) return 0;

        int lh = helper(node->left, d);
        int rh = helper(node->right, d);

        int curDia = lh + rh + 1;
        if(curDia > *d) {
            *d = curDia;
        }
        return max(lh, rh) + 1;
    }
};

/*
Time    = O(N)
Space   = O(H)

method-1: return height and change diameter
method-2: return pair(h, d)
*/
