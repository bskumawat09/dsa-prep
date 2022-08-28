/*
 * https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1
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
    void flatten(Node* root) {
        // Code here
        reversePostorder(root);
    }

private:
    Node* prev = NULL;

    void reversePostorder(Node* node) {
        if(node == NULL) return;

        reversePostorder(node->right);
        reversePostorder(node->left);

        node->right = prev;
        node->left = NULL;
        prev = node;
    }
};

/* -----------Method-2: Iterative----------- */

class Solution2 {
public:
    void flatten(Node* root) {
        stack<Node*> stk;
        stk.push(root);

        while(!stk.empty()) {
            Node* cur = stk.top();
            stk.pop();

            if(cur->right != NULL) stk.push(cur->right);
            if(cur->left != NULL) stk.push(cur->left);

            if(!stk.empty()) {
                cur->right = stk.top();
                cur->left = NULL;
            }
        }
    }
}

/* -----------Method-2: Iterative and O(1) space (Morris Traversal)----------- */

class Solution3 {
public:
    void flatten(Node* root) {
        Node* cur = root;

        while(cur != NULL) {
            if(cur->left != NULL) {
                Node* prev = cur->left;
                while(prev->right != NULL) {
                    prev = prev->right;
                }

                // make the right pointer of last preorder node on left, points to current's right
                // then make current's right points to current's left
                // repeat same for every node
                prev->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
}

/*
Solution-1: Reverse Preorder (Recursive)
Time    = O(N)
Space   = O(H)

Solution-2: Iterative
Time    = O(N)
Space   = O(N)

Solution-3: Morris Traversal (Iterative)
Time    = O(N)
Space   = O(1)

Note: These are reverse of each other,
pre-order   <---> reverse-postorder
post-order  <---> reverse-preorder
(here, reverse means first call right then left)
*/
