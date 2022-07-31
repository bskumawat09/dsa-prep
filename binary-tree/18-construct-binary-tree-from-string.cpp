/*
 * https://practice.geeksforgeeks.org/problems/construct-binary-tree-from-string-with-bracket-representation/1
 *
 */

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

class Solution {
private:
    int i = 0;  // global index to iterate over string

public:
    // "14(2()(4))(17(6))"
    Node* constructTreeFromString(string str) {
        // convert number string (between pair of brackets) to int
        int num = 0;
        while(i < str.length() && str[i] != '(' && str[i] != ')') {
            num = num * 10 + (str[i] - '0');
            i++;
        }

        if(num == 0)  // for empty pair of backets
            return NULL;

        Node* root = new Node(num);

        if(str[i] == '(') {  // encountered '(' for 1st time
            i++;
            root->left = constructTreeFromString(str);
        }
        if(str[i] == '(') {  // encountered '(' for 2nd time
            i++;
            root->right = constructTreeFromString(str);
        }
        if(str[i] == ')') {
            i++;
            return root;
        }
        return root;
    }
};

/*
Time    = O(N)
Space   = O(N)
*/