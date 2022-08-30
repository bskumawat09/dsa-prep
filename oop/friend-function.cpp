#include <iostream>
using namespace std;

class PersonA {
    int weight;

public:
    PersonA(int w = 0) {
        weight = w;
    }

    friend void fun();  // friend function declaration
};

class PersonB {
    int weight;

public:
    PersonB(int w = 0) {
        weight = w;
    }

    friend void fun();
};

void fun() {  // friend funtion definition
    PersonA a(10);
    PersonB b(35);

    cout << "sum: " << a.weight + b.weight << endl;
}

int main() {
    fun();

    return 0;
}
