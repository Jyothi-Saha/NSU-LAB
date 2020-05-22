#include <iostream>
#include "timeStamp.h"
#include "sortedtype.h"

using namespace std;
int main() {

    SortedType<timeStamp> list;
    cout<<"Input: "<<endl;
    for(int i=0; i<5; i++){
        int second=0, minute=0, hour=0;
        cin>>second>>minute>>hour;
        list.InsertItem(timeStamp(second, minute, hour));
    }

    int second = 0, minute = 0, hour = 0;
    cout<<"Timestamp to delete in ss mm hh format"<<endl;
    cin>>second>>minute>>hour;

    list.DeleteItem(timeStamp(second, minute, hour));

    timeStamp output;
    cout<<"Output :"<<endl;
    while(list.GetNextItem(output)){
        output.print();
    }

    return 0;
}
