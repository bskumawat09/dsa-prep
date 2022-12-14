/*
 * https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
 *
 */

class Solution {
private:
    int sum = 0;
    int maxDepth = -1;

public:
    int pathSum(Node* root) {
        _pathSum(root, 0);
        return sum;
    }

    void _pathSum(Node* root, int level, int s) {
        if(root == NULL) return;

        if(root->left == NULL && root->right == NULL) {
            if(level > maxDepth) {
                sum = s + root->data;
                maxDepth = level;
            } else {
                sum = max(sum, s + root->data);
            }
        }

        _pathSum(root->left, level + 1, s + root->data);
        _pathSum(root->right, level + 1, s + root->data);
    }
};

/*
Time    = O(N)
Space   = O(N)
*/
