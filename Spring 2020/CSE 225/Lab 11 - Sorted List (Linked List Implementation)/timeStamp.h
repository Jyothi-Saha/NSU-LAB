#ifndef TIMESTAMP_H_INCLUDED
#define TIMESTAMP_H_INCLUDED

#include <iostream>

class timeStamp{
private:
    int second;
    int minute;
    int hour;

public:
    timeStamp(int, int , int);
    timeStamp();
    void print();

    bool operator<(timeStamp);
    bool operator<=(timeStamp);
    bool operator>(timeStamp);
    bool operator>=(timeStamp);
    bool operator==(timeStamp);
    bool operator!=(timeStamp);
};

#include "timeStamp.tpp"
#endif //TIMESTAMP_H_INCLUDED
