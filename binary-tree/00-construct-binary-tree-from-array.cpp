class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Pair {
public:
    Node* node;
    int state;

    Pair(Node* node, int state) {
        this->node = node;
        this->state = state;
    }
};

class Solution {
public:
    Node* constructor(vector<int> arr) {
        Node* root = new Node(arr[0]);

        stack<Pair*> stk;
        stk.push(new Pair(root, 1));

        int i = 0;

        while(stk.size()) {
            Pair* p = stk.top();

            if(p->state == 1) {
                i++;
                if(arr[i] != -1) {
                    Node* temp = new Node(arr[i]);
                    p->node->left = temp;
                    stk.push(new Pair(temp, 1));
                }
                p->state++;
            } else if(p->state == 2) {
                i++;
                if(arr[i] != -1) {
                    Node* temp = new Node(arr[i]);
                    p->node->right = temp;
                    stk.push(new Pair(temp, 1));
                }
                p->state++;
            } else {
                stk.pop();
            }
        }

        return root;
    }
};
