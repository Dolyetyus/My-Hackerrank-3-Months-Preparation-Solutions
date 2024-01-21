#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

void firstSecond(string &first, string &second, string &s) {
    string temp = s;
    if (s.size() % 2 == 1){
        temp.erase(temp.begin() + (temp.size()/2));
    }
    first = temp.substr(0, temp.size() / 2);
    second = temp.substr(temp.size() / 2, temp.size() / 2);
    reverse(second.begin(), second.end());
}

int palindromeIndex(string s) {
    unsigned int ret = -1;
    bool is_palin = false;
    
    string first;
    string second;
    firstSecond(first, second, s);
        
    if (first==second){
        return -1;
    }
    
    for (unsigned int i = 0; i < first.size(); i++){
        if (first[i] != second[i]){
            string tempfirst;
            string tempsecond;
            string tempS = s;
            tempS.erase(tempS.begin() + i);
            
            firstSecond(tempfirst, tempsecond, tempS);
            
            if (tempfirst == tempsecond){
                ret = i;
            }
            else{
                ret = s.size()-1-i;
            }
            break;
        }
    }
    
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

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
