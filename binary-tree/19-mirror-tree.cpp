/*
 * https://practice.geeksforgeeks.org/problems/mirror-tree/1
 * https://leetcode.com/problems/invert-binary-tree/
 *
 */

class Solution {
public:
    void mirror(Node* node) {
        if(node == NULL) return;

        if(node->left == NULL && node->right == NULL) return;

        mirror(node->left);   // mirror left subtree
        mirror(node->right);  // mirror right subtree

        // mirror current tree by swaping left and right pointers
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
};

/* -----------Method-2----------- */

class Solution2 {
public:
    Node* mirror(Node* root) {
        if(root == NULL)
            return NULL;

        if(root->left == NULL && root->right == NULL)
            return root;

        Node* tempLeft = root->left;

        root->left = mirror(root->right);
        root->right = mirror(tempLeft);
        return root;
    }
};

/* -----------Method-3: Iterative----------- */

class Solution3 {
public:
    void mirror(Node* root) {
        if(root == NULL) return;

        queue<Node*> q;
        q.push(root);

        while(q.size()) {
            Node* node = q.front();

            Node* temp = node->left;
            node->left = node->right;
            node->right = temp;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
};

/*
Solution-1:
Time    = O(N)
Space   = O(H)

Solution-2:
Time    = O(N)
Space   = O(H)

Solution-3:
Time    = O(N)
Space   = O(N)
*/
