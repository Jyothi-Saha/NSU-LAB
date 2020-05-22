#include <iostream>
#include "pqtype.h"
int main() {

    int n = 0;
    cin>>n;

    int k = 0;
    cin>>k;

    PQType<int> candyBags(n);
    for(int i=0; i<n; i++){
        int candies;
        cin>>candies;
        candyBags.Enqueue(candies);
    }

    int totalCandies = 0;
    for(int i=0; i<k; i++){
        int eatenCandy = 0;
        candyBags.Dequeue(eatenCandy);
        totalCandies+=eatenCandy;
        candyBags.Enqueue(eatenCandy/2);
    }

    cout<<totalCandies<<endl;
    return 0;

}
