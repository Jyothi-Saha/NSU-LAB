#include "unsortedtype.h"
#include <iostream>

using namespace std;

template <class ItemType>
UnsortedType<ItemType>::UnsortedType(){
    length = 0;
    listData = NULL;
    currentPos = NULL;
}

template <class ItemType>
int UnsortedType<ItemType>::LengthIs(){
    return length;
}

template<class ItemType>
bool UnsortedType<ItemType>::IsFull(){
    NodeType* location;
    try{
        location = new NodeType;
        delete location;
        return false;
    } catch(bad_alloc& exception){
        return true;
    }
}

template <class ItemType>
bool UnsortedType<ItemType>::InsertItem(ItemType item){
    if(IsFull())
        return false;

    NodeType* location;
    location = new NodeType;
    location->info = item;
    location->next = listData;
    listData = location;
    length++;
    return true;
}

template <class ItemType>
bool UnsortedType<ItemType>::DeleteItem(ItemType item){
    if(LengthIs() == 0)
        return false;

    NodeType* location = listData;
    NodeType* tempLocation;
    if (item == listData->info){
        tempLocation = location;
        listData = listData->next;
    } else{
        while (item!=(location->next)->info){
            location = location->next;
            if(location->next == NULL)
                return false;
        }

        tempLocation = location->next;
        location->next = (location->next)->next;
    }

    delete tempLocation;
    length--;
    return true;
}

template <class ItemType>
bool UnsortedType<ItemType>::RetrieveItem(ItemType& item){
    if(LengthIs() == 0)
        return false;

    NodeType* location = listData;

    while ((location != NULL)){
        if (item == location->info){
            item = location->info;
            return true;
        } else{
            location = location->next;
        }
    }
    return false;
}

template <class ItemType>
void UnsortedType<ItemType>::MakeEmpty(){
    NodeType* tempPtr;
    while (listData != NULL){
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}

template <class ItemType>
UnsortedType<ItemType>::~UnsortedType(){
    MakeEmpty();
}

template <class ItemType>
void UnsortedType<ItemType>::ResetList(){
    currentPos = NULL;
}

template <class ItemType>
bool UnsortedType<ItemType>::GetNextItem(ItemType& item){

    if (currentPos == NULL)
        currentPos = listData;
    else if(currentPos->next == NULL)
        return false;
    else
        currentPos = currentPos->next;
    item = currentPos->info;
    return true;
}
