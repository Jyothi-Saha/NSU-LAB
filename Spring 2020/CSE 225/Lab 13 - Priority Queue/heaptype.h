#ifndef HEAPTYPE_H_INCLUDED
#define HEAPTYPE_H_INCLUDED

using namespace std;
template<class ItemType>
struct HeapType
{
    void ReheapDown(int root, int bottom);
    void ReheapUp(int root, int bottom);

    ItemType* elements;
    //int numElements;
};
#include "heaptype.tpp"
#endif // HEAPTYPE_H_INCLUDED
