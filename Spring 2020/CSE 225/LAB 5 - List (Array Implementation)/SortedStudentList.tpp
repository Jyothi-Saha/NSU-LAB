#include "SortedStudentList.h"
#include <iostream>
using namespace std;

SortedStudentList::SortedStudentList()
{
    length = 0;
    currentPos = - 1;
}
 void SortedStudentList::MakeEmpty()
{
    length = 0;
}

bool SortedStudentList::IsFull()
{
    return (length == MAX_ITEMS);
}
 int SortedStudentList::LengthIs()
{
    return length;
}
 void SortedStudentList::ResetList()
{
    currentPos = - 1;
}

bool SortedStudentList::GetNextItem(StudentInfo& item)
{
    if(currentPos<length-1)
    {
        currentPos++;
        item = info [currentPos];
        return true;
    }
    return false;
}

bool SortedStudentList::InsertItem(StudentInfo item)
{
    if(IsFull())
        return false;
    int location = 0;
    while (location < length)
    {
        if(item.getID() >= info[location].getID())
        {
            location++;
        }
        else
            break;
    }
    for (int index = length; index > location; index--)
        info[index] = info[index - 1];
    info[location] = item;
    length++;
    return true;
}

bool SortedStudentList::DeleteItem(int id)
{
    int location = 0;
    bool deleted = false;
    while (location < length)
    {
        if(id == info[location].getID())
        {
            deleted = true;
            break;
        }
        location++;
    }
    if(!deleted)
        return deleted;
    for (int index = location + 1; index < length; index++)
        info[index - 1] = info[index];
    length--;
    return deleted;
}

bool SortedStudentList::RetrieveItem(StudentInfo& item, int id)
{
    int midPoint, first = 0, last = length - 1;
    //bool found = false;
    while ((first <= last) )
    {
        midPoint = (first + last) / 2;
        if(id < info[midPoint].getID())
        {
            last = midPoint - 1;
        }
        else if(id > info[midPoint].getID())
        {
            first = midPoint + 1;
        }
        else
        {
            //found = true;
            item = info[midPoint];
            return true;
        }
    }
    return false;
}
