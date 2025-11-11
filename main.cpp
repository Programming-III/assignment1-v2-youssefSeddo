#include <iostream>
#include <string>
#include "Person.h"
#include "Student.h"
#include "Instructor.h"
#include "Course.h"


using namespace std;

// ==================== Person Class Implementation =========================

Person::Person() {
    name="Unknown";
    id=0;
}
Person::Person(string name, int id) {
    this->name = name;
    this->id = id;
}
void Person::display() {
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
}
string Person::getName() {
    return name;
}
int Person::getId() {
    return id;
}






// ==================== Student Class Implementation ====================

Student::Student(int yearLevel, string major,string name,int id):Person(name,id){
    this->yearLevel = yearLevel;
    this->major = major;
}
Student::Student():Person("UnKnown Student",0) {
    yearLevel = 0;
    major="Unknown";
}
void Student::display() {
    cout<<"Student Info:"<<endl;
    cout<<"Name: "<<getName()<<endl;
    cout<<"Year: "<<this->yearLevel<<endl;
    cout<<"Major: "<<this->major<<endl;
}
string Student::getMajor() {
    return major;
}
int Student::getYearLevel() {
    return yearLevel;
}




// ==================== Instructor Class Implementation ====================

Instructor::Instructor():Person("Unknown",0) {
    department = "Unknown";
    experienceYears = 0;
}
Instructor::Instructor(string name, int id, int experienceYears, string department):Person(name,id) {
    this->department = department;
    this->experienceYears = experienceYears;
}
void Instructor::display() {
    cout<<"Instructor Info:"<<endl;
    cout<<"Name: "<<getName()<<endl;
    cout<<"Department:"<<this->department<<endl;
    cout<<"Experience: "<<this->experienceYears<<" years"<<endl;
}
string Instructor::getDepartment() {
    return department;
}
int Instructor::getExperienceYears() {
    return experienceYears;
}




// ==================== Course Class Implementation ====================
class Course {
private:
    string courseCode,courseName;
    int maxStudents;
    Student *students;
    int currentStudents;
    Instructor instructor;
public:
    Course() {
        courseCode="Unknown";
        courseName="Unknown";
        maxStudents = 0;
        currentStudents = 0;
        students=new Student[currentStudents];
    }
    Course(string courseCode, string courseName,int maxStudents,int currentStudents) {
        this->courseCode = courseCode;
        this->courseName = courseName;
        this->maxStudents = maxStudents;
        this->currentStudents = currentStudents;
        students=new Student[currentStudents];
    }
    void displayCourseInfo() {
        cout<<"Course:"<<courseName<<endl;
        cout<<"Max Students: "<<maxStudents<<endl;
        cout<<"Currently Enrolled: "<<this->students->getName()<<"(ID: "<<this->students->getId()<<")"<<endl;
        instructor.Instructor::display();
        this->students->Student::display();
    }
    void addStudent(const Student &s) {
        Student* newstudents=new Student[currentStudents+1];
        for (int i=0;i<currentStudents;i++) {
            newstudents[i]=students[i];
        }
        newstudents[currentStudents]=s;
        delete [] students;
        students=newstudents;
        currentStudents++;
    }
    ~Course() {
        delete [] students;
    }
};







// ==================== Main Function ====================
int main() {
    Student s(2007,"CS","Youssef",16004056);
    Instructor i("Omar Nabil",2202,2,"CS");
    Course c("CS101-Introduction to Programming","Database",3,2);
    c.addStudent(s);
    c.displayCourseInfo();

    return 0;
}
