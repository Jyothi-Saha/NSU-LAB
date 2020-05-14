#ifndef SORTEDSTUDENTLIST_H_INCLUDED
#define SORTEDSTUDENTLIST_H_INCLUDED

#include "StudentInfo.h"

class SortedStudentList
{
public :
    SortedStudentList();
    void MakeEmpty();
    bool IsFull();
    int LengthIs();
    bool InsertItem(StudentInfo);
    bool DeleteItem(int);
    bool RetrieveItem(StudentInfo&, int);
    void ResetList();
    bool GetNextItem(StudentInfo&);
private:
    const static int MAX_ITEMS = 3;    // moved here to avoid conflict with UnsortedStudentList class
    int length;
    StudentInfo info[MAX_ITEMS];
    int currentPos;
};

#include "SortedStudentList.tpp"
#endif //SORTEDSTUDENTLIST_H_INCLUDED
