#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string name;
    int age;

    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    Person()
    {
        cout << "I'm parent constructor." << endl;
    }
};

class Student : public Person
{
public:
    int roll;

    Student()
    {
        cout << "I'm child constructor." << endl;
    }
    Student(string name, int age, int roll) : Person(name, age)
    {
        this->roll = roll;
    }
    void getInfo()
    {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
        cout << "roll no: " << roll << endl;
    }
};

int main()
{
    // Student s1;
    // s1.name = "Samruddhi";
    // s1.age = 21;
    // s1.roll = 0014;

    Student s1("samruddhi", 21, 52);
    s1.getInfo();
    return 0;
}