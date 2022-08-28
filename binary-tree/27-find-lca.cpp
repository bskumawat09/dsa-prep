/*
https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

class Node {
public:
    Node* left;
    Node* right;
    int data;

    Node(int data) {
        this->left = this->right = NULL;
        this->data = data;
    }
};
*/

class Solution {
public:
    Node* findLCA(Node* root, int nodeA, int nodeB) {
        // Code here
        vector<Node*> pathA = nodeToRootPath(root, nodeA);
        vector<Node*> pathB = nodeToRootPath(root, nodeB);

        int i = pathA.size() - 1;
        int j = pathB.size() - 1;

        while(i >= 0 && j >= 0 && pathA[i] == pathB[j]) {
            i--;
            j--;
        }

        return pathA[i + 1];
    }

    vector<Node*> nodeToRootPath(Node* root, int node) {
        if(root == NULL) {
            vector<Node*> path;
            return path;
        }

        if(root->data == node) {
            vector<Node*> path = {root};
            return path;
        }

        vector<Node*> path;

        path = nodeToRootPath(root->left, node);
        if(path.size() > 0) {  // if node is found in left subtree
            path.push_back(root);
            return path;
        }

        path = nodeToRootPath(root->right, node);
        if(path.size() > 0) {  // if node is found in right subtree
            path.push_back(root);
            return path;
        }
        return path;
    }
};

/* -----------Method-2: Using single traversal----------- */

class Solution2 {
public:
    Node* findLCA(Node* root, int nodeA, int nodeB) {
        // TODO
    }
};

/*
Solution-1:
Time    = O(N) + O(N) + O(N)    3 traversals
Space   = O(H) + O(2*H)         additional space for storing nodeToRoot paths

Solution-2: Single Traversal (Preffered)
Time    = O(N)
Space   = O(H)
*/
