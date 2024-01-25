#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Editor{
    vector<string> str{""};
    
    void append(string w){
        string newstr = str.back();
        newstr.append(w);
        str.push_back(newstr);
    }
    
    void dlt(int k){
        string newstr = str.back();
        newstr.erase(newstr.size()-k, k);
        str.push_back(newstr);
    }
    
    void print(int k){
        string newstr = str.back();
        cout<<newstr[k-1]<<endl;
    }
    
    void undo(){
        str.pop_back();
    }
};


int main() {
    int operations;
    cin>>operations;
    
    Editor text;
    for (int i = 0; i<operations; i++){
        int type;
        cin >> type;
        
        if (type == 1){
            string str;
            cin >> str;
            text.append(str);
        }
        else if (type == 2){
            int del;
            cin >> del;
            text.dlt(del);
        }
        else if (type == 3){
            int id;
            cin >> id;
            text.print(id);
        }
        else{
            text.undo();
        }
    }
       
    return 0;
}
