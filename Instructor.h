#include<iostream>
using namespace std;
class Instructor:public Person {
    private:
        string department;
        int experienceYears;
    public:
    Instructor(string name, int id, int experienceYears,string department);
    Instructor();
    string getDepartment();
    int getExperienceYears();
    void display();
};












#endif
