#ifndef SORTEDTYPE_H_INCLUDED
#define SORTEDTYPE_H_INCLUDED
template <class ItemType>
class SortedType
{
    struct NodeType
    {
        ItemType info;
        NodeType* next;
    };
public:
    SortedType();
    ~SortedType();
    bool IsFull();
    int LengthIs();
    void MakeEmpty();
    bool RetrieveItem(ItemType&);
    bool InsertItem(ItemType);
    bool DeleteItem(ItemType);
    void ResetList();
    bool GetNextItem(ItemType&);
private:
    int length;
    NodeType* listData;
    NodeType* currentPos;
};
#include "sortedtype.tpp"
#endif // SORTEDTYPE_H_INCLUDED
