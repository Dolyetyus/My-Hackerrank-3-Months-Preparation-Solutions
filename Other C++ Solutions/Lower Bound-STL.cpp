#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, q;
    
    cin>>n;
    vector<int> integers;
    for (int i = 0; i<n; i++){
        int temp;
        cin>>temp;
        integers.push_back(temp);
    }
    
    cin>>q;
    for (int i = 0; i<q; i++){
        int query;
        cin>>query;
        
        int left = 0, right = n - 1;
        bool found = false;
        
        while(left <= right && !found){
            int mid = left+(right - left)/2;
            if (integers[mid] == query){
                int id = 1;
                while (integers[mid-id] == query){
                    id++;
                }
                found = true;
                cout<<"Yes "<<mid-id+2<<endl;
            }
            else if (integers[mid] > query){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        if (!found) {cout<<"No "<<left+1<<endl;}
    }
    
    return 0;
}
