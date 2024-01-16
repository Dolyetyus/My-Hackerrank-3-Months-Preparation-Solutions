#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    for (string line; getline(cin, line);) {
        char first_char = line[0];
        char sec_char = line[2];
        int str_size = line.size();
        string ret_str = "";
        
        if (first_char == 'S'){
            if (sec_char == 'M'){
                ret_str = line.substr(4, str_size-6);
                for (unsigned int i = 0; i < ret_str.size(); i++) {
                    if (std::isupper(ret_str[i])) {
                        ret_str.insert(i, " ");
                        ret_str[i+1] = ret_str[i+1] + 32;
                    }
                }
            }
            else if (sec_char == 'C'){
                ret_str = line.substr(4, str_size-4);
                ret_str[0] = ret_str[0] + 32;
                for (unsigned int i = 0; i < ret_str.size(); i++) {
                    if (std::isupper(ret_str[i])) {
                        ret_str.insert(i, " ");
                        ret_str[i+1] = ret_str[i+1] + 32;
                    }
                }
            }
            else if (sec_char == 'V'){
                ret_str = line.substr(4, str_size-4);
                for (unsigned int i = 0; i < ret_str.size(); i++) {
                    if (std::isupper(ret_str[i])) {
                        ret_str.insert(i, " ");
                        ret_str[i+1] = ret_str[i+1] + 32;
                    }
                }
            }
        }
        
        else if (first_char == 'C'){
            if (sec_char == 'V'){
                ret_str = line.substr(4, str_size-4);
                for (unsigned int i = 0; i < ret_str.size(); i++) {
                    if (ret_str[i] == ' ') {
                        ret_str.replace(i, 1, "");
                        ret_str[i] = ret_str[i] - 32;
                    }
                }
            }
            else if (sec_char == 'C'){
                ret_str = line.substr(4, str_size-4);
                ret_str[0] = ret_str[0] - 32;
                for (unsigned int i = 0; i < ret_str.size(); i++) {
                    if (ret_str[i] == ' ') {
                        ret_str.replace(i, 1, "");
                        ret_str[i] = ret_str[i] - 32;
                    }
                }
            }
            else if (sec_char == 'M'){
                ret_str = line.substr(4, str_size-4);
                for (unsigned int i = 0; i < ret_str.size(); i++) {
                    if (ret_str[i] == ' ') {
                        ret_str.replace(i, 1, "");
                        ret_str[i] = ret_str[i] - 32;
                    }
                }
                ret_str.insert(ret_str.size(), "()");
            }
        }
        cout << ret_str << "\n";
        
    }
    return 0;
}
