#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */

int minimumNumber(int n, string password) {
    string numbers = "0123456789";
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special_characters = "!@#$%^&*()-+";
    
    int numb = 1;
    int lower = 1;
    int upper = 1;
    int special = 1;
    
    for (int i = 0; i< password.size(); i++){
        string chr{password[i]};
        if (numbers.find(chr) != string::npos){
            numb = 0;
        }
        else if (lower_case.find(chr) != string::npos){
            lower = 0;
        }
        else if (upper_case.find(chr) != string::npos){
            upper = 0;
        }
        else if (special_characters.find(chr) != string::npos){
            special = 0;
        }
    }
    
    if (n<6){
        return max(6-n, numb + lower + upper + special);
    }
    else{
        return numb + lower + upper + special;
    }
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

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
