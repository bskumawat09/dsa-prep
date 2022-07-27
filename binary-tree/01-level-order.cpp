/*
https://practice.geeksforgeeks.org/problems/level-order-traversal/1

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
    vector<int> levelOrder(Node *node) {
        // Your code here
        vector<int> ans;
        queue<Node *> q;
        q.push(node);

        while(q.size()) {
            Node *t = q.front();
            q.pop();

            ans.push_back(t->data);

            if(t->left != NULL) q.push(t->left);
            if(t->right != NULL) q.push(t->right);
        }

        return ans;
    }
};

/*
Time    = O(N)
Space   = O(2^H) -> O(N)
*/
