#include <iostream>
#include <vector>
using namespace std;

class Matrix {
    int rows;
    int cols;
    vector<vector<int>> val;

public:
    Matrix(int r, int c) {
        rows = r;
        cols = c;
        val = vector<vector<int>>(r, vector<int>(c, 0));
    }

    Matrix(vector<vector<int>>& arr) {
        rows = arr.size();
        cols = arr[0].size();
        val = arr;
    }

    Matrix operator+(Matrix m) {  // overloaded addition(+) operator
        Matrix sum(rows, cols);

        if(m.rows != rows || m.cols != cols) {
            cout << "ERROR: Matrices must be of same dimensions" << endl;
            return sum;
        }

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                sum.val[i][j] = m.val[i][j] + val[i][j];
            }
        }

        return sum;
    }

    bool operator==(Matrix m) {  // overloaded comparision(==) operator
        if(m.rows != rows || m.cols != cols) {
            return false;
        }

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(val[i][j] != m.val[i][j])
                    return false;
            }
        }

        return true;
    }

    void display() {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                cout << val[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    vector<vector<int>> arr1 = {
        {1, 3, 2},
        {3, 1, 0},
        {2, 0, 4},
    };

    vector<vector<int>> arr2 = {
        {2, 0, 4},
        {3, 1, 0},
        {1, 3, 2},
    };

    Matrix m1(arr1);
    Matrix m2(arr2);
    Matrix m3(arr1);

    Matrix sum = m1 + m2;
    sum.display();

    if(m1 == m3) {
        cout << "Equal" << endl;
    } else {
        cout << "Not Equal" << endl;
    }

    return 0;
}
