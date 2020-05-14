#ifndef UNSORTEDTYPE_H_INCLUDED
#define UNSORTEDTYPE_H_INCLUDED
const int MAX_ITEMS = 3;
template <class ItemType>
class UnsortedType
{
public :
    UnsortedType();
    void MakeEmpty();
    bool IsFull();
    int LengthIs();
    bool InsertItem(ItemType);
    bool DeleteItem(ItemType);
    bool RetrieveItem(ItemType&);
    void ResetList();
    bool GetNextItem(ItemType&);


private:
    int length;
    ItemType info[MAX_ITEMS];
    int currentPos;
};
#include "UnsortedType.tpp"
#endif // UNSORTEDTYPE_H_INCLUDED
