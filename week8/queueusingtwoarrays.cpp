#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

struct Queue {
    stack<int> enq;
    stack<int> deq;

    void enqueue(int x) {
        enq.push(x);
    }

    void moveElements() {
        if (deq.empty()) {
            while (!enq.empty()) {
                deq.push(enq.top());
                enq.pop();
            }
        }
    }

    void dequeue() {
        moveElements();
        if (!deq.empty()) {
            deq.pop();
        }
    }

    void top() {
        moveElements();
        if (!deq.empty()) {
            cout << deq.top()<< endl;
        }
    }
};

int main() {
    Queue queue;
    int q;
    int command;
    int x;
    
    cin >> q;
    for (int i = 0; i < q; i++){
        cin >> command; 
        if (command == 1){
            cin >> x;
            queue.enqueue(x);
        }
        else if (command == 2){
            queue.dequeue();
        }
        else{
            queue.top();
        }
    }
    
    return 0;
}
