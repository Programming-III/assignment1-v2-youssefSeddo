#include<iostream>
using namespace std;
class Person {
    public:
        string name;
        int id;
        virtual void display();
        Person(string name, int id);
        Person();
        string getName();
        int getId();
};













