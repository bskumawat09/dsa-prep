/*
 * https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1
 *
 */

class Solution {
private:
    int depth = -1;

public:
    bool leafAtSameLevel(Node* root) {
        return helper(root, 0);
    }

    bool helper(Node* root, int l) {
        if(root == NULL) return true;

        if(!root->left && !root->right) {
            if(depth == -1)
                depth = l;
            else
                return l == depth;
        }

        if(helper(root->left, l + 1) == false) return false;
        if(helper(root->right, l + 1) == false) return false;

        return true;
    }
};

/*
Time    = O(N)
Space   = O(N)
*/
