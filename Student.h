#include<iostream>
using namespace std;
class Student:public Person {
    public:
        int yearLevel;
        string major;
        Student(int yearLevel, string major,string name,int id);
        Student();
        void display();
        int getYearLevel();
        string getMajor();


};
