#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'alternate' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int alternate(string s) {
    int ret = 0;
    
    if (s.size()<2){
        return 0;
    }
    
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            string check;
            char char1 = 'a' + i;
            char char2 = 'a' + j;
            bool compare = true;
            
            for (int i = 0; i<s.size(); i++){
                if (s[i] == char1 || s[i] == char2){
                    check.push_back(s[i]);
                }
            }
            
            for (int i = 0; i < check.size() - 1; i++) {
                if (check[i] != check[i + 2] && check[i] == check[i + 1]) {
                    compare = false;
                    break;
                }
            }
            
            if (compare){
                int size = check.size();
                ret = max(size, ret);
            }
            
        }
    }

    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
