#include <iostream>
#include "Queue.h"

using namespace std;
int main() {

    Queue <string> binary;

    int n;
    cin>>n;
    if(n==0) {
        cout << 0 << endl;
        return 0;
    }
    cout<<n<<endl;
    try {
        binary.Enqueue("1");
    }
    catch (fullQueue& e){
        e.printmsg();
    }

    int i=1;
    while(i<=n){
        string bin;
        try {
            binary.Dequeue(bin);
        }catch(emptyQueue& e){}

        cout<<"bin of "<<i<<" : "<<bin<<endl;
        if(i<=(n/2)){     // to prevent unnecessary enqueue operation
            /*
             *  After every deque, we are generating two more numbers and enqueuing them.
             *  Hence in total we would get 2n+1 numbers in total if n%2 == 0. Otherwise 2n numbers in total.
             *  After this condition we will have n+1 numbers in total if n%2 == 0. Otherwise n numbers.
             *
             * */

            try {
                binary.Enqueue(bin+"0");
                if( (n%2==0) && (i==n/2) ) {    // to not enqueue the extra number when n%2==0
                    i++;
                    continue;
                }
                binary.Enqueue(bin+"1");
            }catch (fullQueue& e){
                e.printmsg();
                int neededSize = ((n%2 == 0)?(n/2):(n/2)+1);
                cout<<"Increase max size to: "<<neededSize<<endl;
                return 0;       //if number is too large and there are too many numbers to handle, exit the program here
            }
        }


        i++;
    }

    //uncomment the following part and the comment out the optimising conditions to check the issue the leftover values in the queue

//    cout<<endl<<"leftover checking"<<endl;
//    int count = 1;
//    while(!binary.isEmpty())
//    {   string leftover;
//        binary.Dequeue(leftover);
//        cout<<count<<": "<<leftover<<endl;
//        count++;
//    }
    return 0;
}
