#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

void print (int start, int finish, int arr[]){
    if(start == finish){
        cout << arr[start] << " ";
        return;
    }
    int mid = (finish + start) / 2;
    cout<<arr[mid]<<" ";
    if((mid-1)>=start)
        print(start, mid - 1, arr);
    if((mid+1)<=finish)
        print(mid+1, finish, arr);
}

int main() {
    int n = 0;
    cin>>n;

    TreeType<int> inputTree;
    for(int i=0; i<n; i++){
        int in = 0;
        cin>>in;
        inputTree.InsertItem(in);
    }

    inputTree.ResetTree(IN_ORDER);
    int sortedSequence[n];
    for(int i=0; i<n; i++){
        bool found;
        inputTree.GetNextItem(sortedSequence[i], IN_ORDER, found);

    }

    cout<<endl<<"Output: "<<endl;
    print(0,n-1,sortedSequence);

    return 0;
}
