#include <iostream>
#include "StudentInfo.h"
#include "UnsortedStudentList.h"
#include "SortedStudentList.h"

using namespace std;

int main() {

    UnsortedStudentList UL;
    SortedStudentList SL;
    while(!UL.IsFull()) {
        int id;
        string name;
        double CGPA;

        cin>>id>>name>>CGPA;
        UL.InsertItem(StudentInfo(id,name,CGPA));
        SL.InsertItem(StudentInfo(id, name, CGPA));
    }

    StudentInfo demo;

    cout<<"Printing unsorted list: "<<endl;
    while(UL.GetNextItem(demo)){
        demo.print();
    }

    cout<<"Printing sorted list: "<<endl;
    while(SL.GetNextItem(demo)){
        demo.print();
    }

    return 0;
}
