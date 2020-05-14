#ifndef STUDENTINFO_H_INCLUDED
#define STUDENTINFO_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;

class StudentInfo {

private:
    int id;
    string name;
    double CGPA;

public:

    StudentInfo(){
       // do nothing
    }

    StudentInfo(int id, string name, double CGPA){
        this->id = id;
        this->name = name;
        this->CGPA = CGPA;
    }

    void print(){
        cout<<"Name: "<<name<<", ID: "<<id<<", CGPA: "<<CGPA<<endl;
    }

    int getID(){return id;}
    string getName(){return name;}
    double getCGPA(){return CGPA;}

};


#endif // STUDENTINFO_H_INCLUDED
