/*
 *  Before checking the following solution we need to understand that the implementation of
    unsorted list is done in such a way that we get the items using getNextItem in reversed
    order of insertion. So if we insert in ascendig order, we get them in descending order
    and vice versa.

 * */

#include <iostream>
#include "unsortedtype.h"

using namespace std;

int main() {
    UnsortedType<int> list1, list2, combinedList;

    int m = 0;
    cin>>m;
    for(int i=0; i<m; i++){
        int temp = 0;
        cin>>temp;
        list1.InsertItem(temp);     // remember that inputs are arranged in ascending order
    }

    int n = 0;
    cin>>n;
    for(int i=0; i<n; i++){
        int temp = 0;
        cin>>temp;
        list2.InsertItem(temp);
    }

    int l1 = 0, l2 = 0;
    list1.GetNextItem(l1);      // we will get the values in descending order so larger values first
    list2.GetNextItem(l2);
    bool flag1 = true, flag2 = true;

    while(flag1 || flag2){          // checking if any of the input sequences have values left to be used
        if(flag1 && flag2) {        // if both of the lists have value
            if (l1 > l2) {

                /*
                 *  Output needs to be in ascending order hence we
                    need to insert larger values first so that when
                    using GetNextItem to get output from list, we
                    will get them in ascending order.
                */

                combinedList.InsertItem(l1);
                flag1 = list1.GetNextItem(l1);  // retrieving value from list1 to l1 and also updating flag
            } else {
                combinedList.InsertItem(l2);
                flag2 = list2.GetNextItem(l2);
            }
        } else if (flag1){      // when only list1 has values
            combinedList.InsertItem(l1);
            flag1 = list1.GetNextItem(l1);
        } else{                 // when only list 2 has values
            combinedList.InsertItem(l2);
            flag2 = list2.GetNextItem(l2);
        }
    }

    // Printing output
    int output = 0;
    while(combinedList.GetNextItem(output)){
        cout<<output<<" ";
    }

    return 0;
}
