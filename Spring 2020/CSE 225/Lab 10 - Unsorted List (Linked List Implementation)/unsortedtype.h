#ifndef UNSORTEDTYPE_H_INCLUDED
#define UNSORTEDTYPE_H_INCLUDED

template <class ItemType>
class UnsortedType
{
    struct NodeType
    {
        int info;
        NodeType* next;

    };

public:
    UnsortedType();
    ~UnsortedType();
    bool IsFull();
    int LengthIs();
    void MakeEmpty();
    bool RetrieveItem(ItemType&);
    bool InsertItem(ItemType);
    bool DeleteItem(ItemType);
    void ResetList();
    bool GetNextItem(ItemType&);

private:
    NodeType* listData;
    int length;
    NodeType* currentPos;
};
#include "unsortedtype.tpp"
#endif // UNSORTEDTYPE_H_INCLUDED
