#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

/*
Too slow for some tests:

struct Heap{
    vector<long> heap;
    
    void insert(long n){
        heap.push_back(n);
    }
    
    void del(long n){
        heap.erase(remove(heap.begin(),heap.end(),n),heap.end());
    }
    
    void print(){
        long min = *min_element(heap.begin(), heap.end());
        cout<<min<<endl;
    }
};*/

struct Heap {
    set<long> heap;

    void insert(long n) {
        heap.insert(n);
    }

    void del(long n) {
        heap.erase(n);
    }

    void print() {
        cout << *(heap.begin()) << endl;
    }
};

int main() {
    unsigned int queries;
    cin>>queries;
    Heap heap;
    
    for (unsigned int i = 0; i<queries; i++){
        int operation;
        cin>>operation;
        
        if (operation == 1){
            long n;
            cin>>n;
            heap.insert(n);
        }
        else if (operation == 2){
            long n;
            cin>>n;
            heap.del(n);
        }
        else{
            heap.print();
        }
    }  
    return 0;
}
