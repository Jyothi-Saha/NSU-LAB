//  following solution is an optimization of the solution provided here:
//  https://github.com/mhasan502/CSE225/tree/master/Lab%2009

#include <iostream>
#include "QueueType.h"

using namespace std;

int main() {

    int size;
    cin>>size;

    QueueType<int> amounts, numOfCoins;

    int coinTypes[size];
    for(int i=0; i<size; i++){
        cin>>coinTypes[i];
        amounts.EnQueue(coinTypes[i]);
        numOfCoins.EnQueue(1);
    }

    int totalMoney;
    cin>>totalMoney;

    int currentTotal = 0, currentNumOfCoins = 0;
    bool found  = false;

    while(!found){
        amounts.DeQueue(currentTotal);
        numOfCoins.DeQueue(currentNumOfCoins);

        if(currentTotal==totalMoney)
            break;
        else{
            currentNumOfCoins++;
            for(int i=0; i<size; i++){
                // this program will work even without the following if block.
                // but this block optimizes the code to reduce unnecessary enqueue and dequeue operations
                // we are terminating all operations as soon as we reach our desired total amount
                if(currentTotal+coinTypes[i] == totalMoney){
                    found = true;
                    currentTotal += coinTypes[i];
                    break;
                }
                amounts.EnQueue(currentTotal + coinTypes[i]);
                numOfCoins.EnQueue(currentNumOfCoins);
            }
        }

    }

    cout<<currentNumOfCoins<<endl;

    return 0;
}
