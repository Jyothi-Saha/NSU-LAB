#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
using namespace std;
const int MAX_SIZE = 100;

class emptyQueue{};
class fullQueue{
private:
    string msg;
public:
    fullQueue() {}
    fullQueue(string msg){ this->msg = msg; }
    void printmsg(){ cout<<msg<<endl; }
};

template<class ItemType>
class Queue{

private:
    ItemType data [MAX_SIZE];
    int front;
    int rear;

public:
    Queue();
    bool isEmpty();
    bool isFull();
    void Enqueue(ItemType);
    void Dequeue(ItemType&);
};
#include "Queue.tpp"
#endif // QUEUE_H_INCLUDED
