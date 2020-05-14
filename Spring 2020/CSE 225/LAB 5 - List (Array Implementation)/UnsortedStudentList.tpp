// this is modified from UnsortedType.tpp to accommodate StudentInfo class only.

#include "UnsortedStudentList.h"

UnsortedStudentList::UnsortedStudentList()
{
    length = 0;
    currentPos = -1;
}


void UnsortedStudentList::MakeEmpty()
{
    length = 0;
}


bool UnsortedStudentList::IsFull()
{
    return (length == MAX_ITEMS);
}


int UnsortedStudentList::LengthIs()
{
    return length;
}


void UnsortedStudentList::ResetList()
{
    currentPos = -1;
}


bool UnsortedStudentList::GetNextItem(StudentInfo& item)
{
    if(currentPos<length-1)
    {
        currentPos++;
        item = info [currentPos];
        return true;
    }
    return false;
}


bool UnsortedStudentList::RetrieveItem(StudentInfo& item, int id)
{
    int location = 0;
    while ((location < length))
    {
        if(id == info[location].getID())
        {
            item = info[location];
            return true;
        }
        else
        {
            location++;
        }
    }
    return false;
}

bool UnsortedStudentList::InsertItem(StudentInfo item)
{
    if(!IsFull())
    {
        info[length] = item;
        length++;
        return true;
    }
    return false;
}


bool UnsortedStudentList::DeleteItem(int id)
{
    int flag = 0;
    int location = 0;
    while (location < length )
    {
        if(id == info[location].getID())
        {
            flag = 1;
            break;
        }
        location++;
    }
    if(flag==1)
    {
        info[location] = info[length - 1];
        length--;
        return true;
    }
    return false;
}
