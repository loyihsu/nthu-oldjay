#include<iostream>
#include<string.h>
#include "function.h"

using namespace std;

int main(){
    List_queue L_queue;
    char command[10];
    int n;

    while(cin>>command){
        if(strcmp(command,"dequeue")==0) {
            L_queue.dequeue();
        } else if(strcmp(command,"enqueue")==0) {
            cin >> n;
            L_queue.enqueue(n);
        } else if(strcmp(command, "print") == 0) {
            L_queue.print();
            cout << endl;
        }
    }
    
    return 0;
}
