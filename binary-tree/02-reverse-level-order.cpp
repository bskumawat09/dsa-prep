/*
https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1

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
    vector<int> reverseLevelOrder(Node *root) {
        // code here
        vector<int> ans;

        queue<Node *> q;
        stack<int> stk;
        q.push(root);

        while(q.size()) {
            Node *t = q.front();
            q.pop();

            stk.push(t->data);

            if(t->right != NULL) q.push(t->right);
            if(t->left != NULL) q.push(t->left);
        }

        while(stk.size()) {
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};

/*
Time    = O(N)
Space   = O(2^H) -> O(N)
*/
