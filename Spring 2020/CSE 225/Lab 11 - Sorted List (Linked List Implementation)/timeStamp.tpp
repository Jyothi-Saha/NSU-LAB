#include "timeStamp.h"
using namespace std;
timeStamp::timeStamp(int second, int minute, int hour){
    this->second = second;
    this->minute = minute;
    this->hour = hour;
}

timeStamp::timeStamp(){
    this->second = 0;
    this->minute = 0;
    this->hour = 0;
}

void timeStamp::print(){
    cout<<second<<":"<<minute<<":"<<hour<<endl;
}

bool timeStamp::operator==(timeStamp t) {
    return (this->second==t.second && this->minute==t.minute && this->hour==t.hour);
}
bool timeStamp::operator<(timeStamp t) {
    if(this->hour<t.hour)
        return true;
    else if(this->hour==t.hour){
        if(this->minute<t.minute){
            return true;
        }
        else if(this->minute==t.minute){
            return this->second < t.second;
        } else {
            return false;
        }
    } else{
        return false;
    }
}

bool timeStamp::operator>(timeStamp t) {
    return ( !(*this<t) && !(*this==t) );
}

bool timeStamp::operator!=(timeStamp t) {
    return !(*this==t);
}

bool timeStamp::operator<=(timeStamp t){
    return ( (*this==t) || (*this<t) );
}

bool timeStamp::operator>=(timeStamp t) {
    return ( (*this==t) || (*this>t));
}

