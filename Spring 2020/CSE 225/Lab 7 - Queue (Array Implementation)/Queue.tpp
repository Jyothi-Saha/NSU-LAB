#include "Queue.h"

template<class ItemType>
Queue<ItemType>::Queue(){
    this->front = -1;
    this->rear = -1;
}

template<class ItemType>
bool Queue<ItemType>::isEmpty(){
    //return (this->front==this->rear && this->front==-1);
    return (this->front == -1 && this->rear == -1);
}

template<class ItemType>
bool Queue<ItemType>::isFull(){
    return ((this->rear+1)%MAX_SIZE==this->front);
//    if(this->rear==MAX_SIZE-1 && this->front==0)
//        return true;
//    else if(this->rear+1 == this->front)
//        return true;
//    else
//        return false;

}

template<class ItemType>
void Queue<ItemType>::Enqueue(ItemType item){
    if(isFull())
        throw fullQueue("Failed to enqueue "+item+", queue is full.");
    else if(isEmpty()){
        this->front++;
        this->rear++;
        data[this->rear] = item;
    }
    else
    {
        this->rear=(this->rear+1)%MAX_SIZE;
//        if(this->rear = MAX_SIZE-1)
//            this->rear = 0;
//        else
//            this->rear++;

        data[this->rear] = item;
    }
}

template<class ItemType>
void Queue<ItemType>::Dequeue(ItemType& item) {
    if(isEmpty())
        throw emptyQueue();
    else if((this->front==this->rear)){
        item = data[this->front];
        this->front = -1;
        this->rear = -1;
    }
    else{
        item = data[this->front];
        this->front=(this->front+1)%MAX_SIZE;
//        if(this->front==MAX_SIZE-1)
//            this->front = 0;
//        else
//            this->front++;
    }
}
