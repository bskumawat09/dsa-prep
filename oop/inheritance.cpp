#include <bits/stdc++.h>
using namespace std;

class Person {
protected:
    string name;
    string gender;
    int age;

public:
    Person() {
        name = "";
        age = 0;
        gender = "";
    }

    Person(string name, int age, string gender) {
        this->name = name;
        this->age = age;
        this->gender = gender;
    }

    void display() {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
        cout << "gender: " << gender << endl;
    }

    void display(string salutation) {  // overloaded display() funtion
        cout << "name: " << salutation << name << endl;
        cout << "age: " << age << endl;
        cout << "gender: " << gender << endl;
    }
};

class Employee : private Person {
private:
    int salary;

protected:
    int yearOfExp;

public:
    Employee() {
        yearOfExp = 0;
        salary = 0;
    }

    Employee(string name, int age, string gender, int yoe, int salary)
        : Person(name, age, gender) {
        this->yearOfExp = yoe;
        this->salary = salary;
    }

    void display() {  // overriden display() function
        Person::display();
        cout << "yearOfExp: " << yearOfExp << endl;
        cout << "salary: " << salary << endl;
    }

    void bonus() {
        // 'name' is protected, thus it is accessible in derived class.
        cout << "Hi " << name << ", You have been awarded with Rs." << 25000 << " as a festival bonus." << endl;
    }
};

int main() {
    Employee e1("Murarilal", 45, "Male", 18, 1450000);
    e1.display();
    // e1.display("Mr."); /* cause error */
    e1.bonus();

    return 0;
}

/*
constructor invokation in base & derived classes
destructor invokation in base & derived classes
modes of inheritance: public, protected, private
types of inheritance: multi-level, multiple
diamond problem
*/