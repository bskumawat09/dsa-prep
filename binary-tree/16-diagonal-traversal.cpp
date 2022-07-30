/*
 * https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
 *
 */

class Solution {
public:
    vector<vector<int>> diagonal(Node* root) {
        vector<vector<int>> ans;

        queue<Node*> q;
        q.push(root);

        // traverse each diagonal
        while(q.size()) {
            int n = q.size();
            vector<int> diagonal;

            // traverse each component in a diagonal
            for(int i = 0; i < n; i++) {
                Node* node = q.front();
                q.pop();

                // traverse a component
                while(node != NULL) {
                    diagonal.push_back(node->data);
                    if(node->left != NULL) q.push(node->left);

                    node = node->right;
                }
            }
            ans.push_back(diagonal);
        }

        return ans;
    }
};

/*
Intuition:
For every node in the queue, keep traversing to right child and simultaneously add left childs (if present) in the queue.
Queue will store first node of every diagonal component.

Time    = O(N)
Space   = O(N)
*/