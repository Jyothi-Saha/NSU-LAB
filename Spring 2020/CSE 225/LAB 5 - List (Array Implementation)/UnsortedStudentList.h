// this is modified from UnsortedType.h to accommodate StudentInfo class only.

#ifndef UNSORTEDSTUDENTLIST_H_INCLUDED
#define UNSORTEDSTUDENTLIST_H_INCLUDED
#include "StudentInfo.h"

const int MAX_ITEMS = 3;

class UnsortedStudentList
{
public :
    UnsortedStudentList();
    void MakeEmpty();
    bool IsFull();
    int LengthIs();
    bool InsertItem(StudentInfo);
    bool DeleteItem(int);
    bool RetrieveItem(StudentInfo&, int);
    void ResetList();
    bool GetNextItem(StudentInfo&);


private:
    int length;
    StudentInfo info[MAX_ITEMS];
    int currentPos;
};

#include "UnsortedStudentList.tpp"
#endif //UNSORTEDSTUDENTLIST_H_INCLUDED
